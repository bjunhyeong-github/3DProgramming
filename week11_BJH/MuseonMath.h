#pragma once
#include <iostream>
#include <math.h>

#define N 3  

using namespace std;
class Mat3 {
public:
    float Mat[3][3]; // 2�������

    Mat3() { //  ��� ������
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                Mat[i][j] = 0; // ��� ���� �ʱ�ȭ
            }
        }
    }
    void Reset() { // ��� �ʱ�ȭ �Լ�
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                Mat[i][j] = 0;
            }
        }
        Mat[2][2] = 1; //2���� ��ǥ���� z���� �������� �������� 1�� �ʱ�ȭ
    }

    void Translate(float x, float y)
    {
        Reset();
        Mat[0][0] = 1;
        Mat[1][1] = 1;
        Mat[2][0] = x;
        Mat[2][1] = y;
        // �̵� ��ȯ ��� ���Ŀ� �°� ����
    }

    void Rotate(float r)
    {
        Reset();
        double Rotate = r * (3.14 / 180); // ���� ����
        Mat[0][0] = cos(Rotate);
        Mat[0][1] = (-sin(Rotate));
        Mat[1][0] = sin(Rotate);
        Mat[1][1] = cos(Rotate);
        // ȸ�� ��ȯ ��� ���Ŀ� �°� ����
    }

    void Scale(float s)
    {
        Reset();
        Mat[0][0] = s;
        Mat[1][1] = s;
        // ũ�� ��ȯ ��� ���Ŀ� �°� ����
    }

};

class Vec3 {
public:
    float Position[2]; // 2������ǥ+������ǥ

    Vec3(float x, float y) { // ������
        Position[0] = x;
        Position[1] = y;
    }

    Vec3 operator *(Mat3& p) // ������ �����ε�
    {
        float x = Position[0]; // 3*1����� x����
        float y = Position[1]; // 3*1����� y����
        float z = 1; // 3*1����� z����
        float a = (x * p.Mat[0][0]) + (y * p.Mat[1][0]) + (z * p.Mat[2][0]); // ��İ� x��ǥ ����� ����
        float b = (x * p.Mat[0][1]) + (y * p.Mat[1][1]) + (z * p.Mat[2][1]); // ��İ� y��ǥ ����� ����
        // Z��ǥ�� 2�������� �ʿ�����Ƿ� ����
        return Vec3(a, b); // ����� x,y��ǥ ����
    }
};


#include<iostream>
#include <cmath>

using namespace std;


void UnitMat() {

    cout << "������� \n";
    float Mat[3][3];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            Mat[i][j] = 0;  //��� �ʱ�ȭ
        }
    }
    Mat[0][0] = 1;
    Mat[1][1] = 1;
    Mat[2][2] = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << Mat[i][j] << " ";
        }
        cout << "\n";
    }
};

void tpMat()
{
    int m = 3;
    int n = 3;
    int matrix[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
    int transpose[3][3];
    int i, j;


    //transpose ����� ��ġ��ķ� �ٲٱ�
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            transpose[i][j] = matrix[j][i];


    //��ġ��� �ٲٱ� �� ���
    printf("��ġ��� �ٲٱ� �� ���\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            printf("%d\t", matrix[i][j]);
        printf("\n");
    }
    printf("\n");

    //��ġ��� �ٲ� �� ���
    printf("��ġ��� �ٲ� �� ���\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)\
            printf("%d\t", transpose[i][j]);
        printf("\n");
    }
    return;
}


void multiplyMat() {

    // �迭 ����
    int first[3][3];
    int second[3][3];
    int result[3][3];

    // ù ���� ��� �Է�
    cout << endl << "| ��� a �Է� |" << "\n\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << "Enter a" << i + 1 << " / b" << j + 1 << " :\t";
            cin >> first[i][j];
        }
    }
    // �� ��° ��� �Է�
    cout << endl << "| ��� b �Է� |" << "\n\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << "Enter b" << i + 1 << " / b" << j + 1 << " :\t ";
            cin >> second[i][j];
        }
    }

    // �Է��� ��� ���
    cout << "| �Էµ� ��İ� |" << "\n\n";
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

    // ù��° ��� x �ι�° ��� ���
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            int sum = 0;
            for (int k = 0; k < 3; ++k) {
                sum += first[i][k] * second[k][j];
            }
            result[i][j] = sum;
        }
    }

    // ��� �� ���
    cout << endl << "| ��°� | " << "\n\n";
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
       {9, 8, 7},
       {6, 5, 4},
       {3, 2, 1}
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