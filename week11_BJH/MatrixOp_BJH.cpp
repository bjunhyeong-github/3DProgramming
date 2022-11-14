#include <iostream>
#include <math.h>
#include "MusoenMath.h"
 

void main()
{
	Vec3 Vector(0, 0);                 //������ 0,0���� ����
	Mat3 Matrix;                       // ��� ����

	Matrix.Translate(3, 5);            // x=3, y=5��ŭ ��ǥ�̵�
	Vector = Vector * Matrix;          // ������ �����ε����� ���Ϳ� ��� ���
	Matrix.Rotate(30);                 // 30����ŭ ȸ��
	Vector = Vector * Matrix;          // ������ �����ε����� ���Ϳ� ��� ���
	Matrix.Scale(2);                   // ũ�⸦ 2�� Ȯ��
	Vector = Vector * Matrix;          // ������ �����ε����� ���Ϳ� ��� ���

	cout << fixed;
	cout.precision(0);                 //�Ҽ����� �����ϸ鼭 ���������� ��ǥ����
	cout << "0,0���� (3,5)��ŭ�̵�,30��ȸ��,2�� Ȯ���������� ��ǥ����: ";
	cout << Vector.Position[0] << "," << Vector.Position[1] << "�Դϴ�." << endl;

	UnitMat();
	tpMat();
	multiplyTransposeMat();
	multiplyMat();
	

}