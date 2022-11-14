#pragma once
#include <iostream>
#include <math.h>

#define N 3  

using namespace std;
class Mat3 {
public:
    float Mat[3][3];                                 // 3x3 2차원행렬

    Mat3() {                                         //  행렬 생성
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                Mat[i][j] = 0;                       // 멤버변수 초기화
            }
        }
    }
    void Reset() {                                   // 행렬초기화 함수(쓰레기 값이 나오기때문에 초기화)
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                Mat[i][j] = 0;
            }
        }
        Mat[2][2] = 1;                               //2차원 좌표에서 z축은 존재하지 않음으로 1값으로 초기화
    }

    void Translate(float x, float y)
    {
        Reset();
        Mat[0][0] = 1;                               //이동변환 행렬 공식에 맞게 설정
        Mat[1][1] = 1;
        Mat[2][0] = x;
        Mat[2][1] = y;
    }

    void Rotate(float r)
    {
        Reset();
        double Rotate = r * (3.14 / 180);            //회전공식 설정
        Mat[0][0] = cos(Rotate);
        Mat[0][1] = (-sin(Rotate));
        Mat[1][0] = sin(Rotate);
        Mat[1][1] = cos(Rotate);                     //회전변환 행렬 공식에 맞게 설정
    }

    void Scale(float s)
    {
        Reset();
        Mat[0][0] = s;
        Mat[1][1] = s;                               // 크기 변환 행렬 공식에 맞게 설정
    }

};

class Vec3 {
public:
    float Position[2];                             // 2차원좌표+동차좌표

    Vec3(float x, float y) {                       // 생성자
        Position[0] = x;
        Position[1] = y;
    }

    Vec3 operator *(Mat3& p)                      // 연산자 오버로딩
    {
        float x = Position[0];                    // 3*1행렬의 x설정
        float y = Position[1];                    // 3*1행렬의 y설정
        float z = 1;                              // 3*1행렬의 z설정
        float a = (x * p.Mat[0][0]) + (y * p.Mat[1][0]) + (z * p.Mat[2][0]); // 행렬곱 x좌표 결과값 저장    
        float b = (x * p.Mat[0][1]) + (y * p.Mat[1][1]) + (z * p.Mat[2][1]); // 행렬곱 y좌표 결과값 저장         
                                                  // Z좌표는 2차원에선 필요없으므로 생략                         
        return Vec3(a, b);                        // 저장된 x,y좌표 리턴
    }
};

void UnitMat() {                                        // 단위행렬 생성함수

    cout << "단위행렬 \n";                                   
    float Mat[3][3];                                    // 3x3 2차원행렬

    for (int i = 0; i < 3; i++) {                       // 행렬 생성
        for (int j = 0; j < 3; j++) {
            Mat[i][j] = 0;                              // 멤버변수 초기화 ==  000  으로 초기화
        }                                               //                     000  (안해주면 쓰레기값 생성)
    }                                                   //                     000     
    Mat[0][0] = 1;                                      // 100 
    Mat[1][1] = 1;                                      // 010
    Mat[2][2] = 1;                                      // 001  으로 초기화
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {                   //행렬을 출력해주는 for문
            cout << Mat[i][j] << " ";
        }
        cout << "\n";
    }
};

void tpMat()                                            //전치행렬 생성코드
{           
    int m = 3;                                          //[][]에 들어갈 변수 생성1 
    int n = 3;                                          //[][]에 들어갈 변수 생성2 
    int matrix[3][3] = { {1,2,3},{4,5,6},{7,8,9} };     //행렬 하나 생성
    int transpose[3][3];                                //전치행렬이 될 3x3의 빈공간의 배열 생성
    int i, j;


    for (i = 0; i < m; i++)                             //transpose 행렬을 전치행렬로 바꾸기
        for (j = 0; j < n; j++)
            transpose[i][j] = matrix[j][i];             //i와j의 값을 바꾸어 전치행렬처럼 행렬의 값이 변하게 함

    printf("전치행렬 바꾸기 전 행렬\n");                //전치행렬 바꾸기 전 행렬
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            printf("%d\t", matrix[i][j]);
        printf("\n");
    }
    printf("\n");

    printf("전치행렬 바꾼 후 행렬\n");                   //전치행렬 바꾼 후 행렬
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)\
            printf("%d\t", transpose[i][j]);
        printf("\n");
    }
    return;
}


void multiplyMat() {

    int first[3][3];                                   // 배열 선언
    int second[3][3];
    int result[3][3];

    cout << endl << "| 행렬 a 입력 |" << "\n\n";       // 첫 번쨰 행렬 입력
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << "Enter a" << i + 1 << " / b" << j + 1 << " :\t";
            cin >> first[i][j];
        }
    }
    cout << endl << "| 행렬 b 입력 |" << "\n\n";       // 두 번째 행렬 입력
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << "Enter b" << i + 1 << " / b" << j + 1 << " :\t ";
            cin >> second[i][j];
        }
    }
    cout << "| 입력된 행렬값 |" << "\n\n";             // 입력한 행렬 출력
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << first[i][j] << " ";
        }
        cout << "\t";
        for (int j = 0; j < 3; j++) {
            cout << second[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < 3; ++i) {                      // 첫번째 행렬 x 두번째 행렬 계산
        for (int j = 0; j < 3; ++j) {
            int sum = 0;
            for (int k = 0; k < 3; ++k) {
                sum += first[i][k] * second[k][j];
            }
            result[i][j] = sum;
        }
    }
    cout << endl << "| 출력값 | " << "\n\n";           // 행렬 곱 출력
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << " " << result[i][j];
        }
        cout << endl;
    }
}



void multiply(int arr1[][N], int arr2[][N], int arr3[][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            arr3[i][j] = 0;
            for (int k = 0; k < N; k++) {
                arr3[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
}

void multiplyTransposeMat() {
    int arr1[N][N] = {
       {1, 2, 3},
       {4, 5, 6},
       {7, 8, 9}
    };

    int arr2[N][N] = {
       {1, 4, 7},
       {2, 5, 8},
       {3, 6, 9}
    };

    int arr3[N][N];

    multiply(arr1, arr2, arr3);

    cout << "arr1 = " << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << +arr1[i][j] << " ";
        }
        cout << endl;
    }
    printf("\n");


    cout << "arr2 = " << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << arr2[i][j] << " ";
        }
        cout << endl;
    }
    printf("\n");

    cout << "arr1 * arr2 = " << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << arr3[i][j] << " ";
        }
        cout << endl;
    }
}
