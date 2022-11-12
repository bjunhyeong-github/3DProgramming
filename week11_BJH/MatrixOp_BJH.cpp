#include <iostream>
#include <math.h>
#include "BJHfile.h"
 
using namespace std;
class MatOp                                         //��������� �ʱ�ȭ���ִ� �Լ�
{
public:
    float Mat[3][3];                                 // 3x3 2�������

    MatOp() {                                         //  ��� ����
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                Mat[i][j] = 0;                       // ������� �ʱ�ȭ
            }
        }
    }
    void Reset() {                                   // ����ʱ�ȭ �Լ�(������ ���� �����⶧���� �ʱ�ȭ)
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                Mat[i][j] = 0;
            }
        }
        Mat[0][0] = 1;
        Mat[1][1] = 1;
        Mat[2][2] = 1;                               //2���� ��ǥ���� z���� �������� �������� 1������ �ʱ�ȭ
    }

};

int main()
{
    int m = 3;
    int n = 3;
    int matrix[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
    int transpose[3][3];
    int i, j;

    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            transpose[i][j] = matrix[j][i];

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            printf("%d\t", matrix[i][j]);
        printf("\n");
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            printf("%d\t", transpose[i][j]);
        printf("\n");
    }
    return 0;
}