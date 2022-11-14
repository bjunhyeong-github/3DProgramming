#include <iostream>
#include <math.h>
#include "MusoenMath.h"
 

void main()
{
	Vec3 Vector(0, 0);                 //원점을 0,0으로 설정
	Mat3 Matrix;                       // 행렬 생성

	Matrix.Translate(3, 5);            // x=3, y=5만큼 좌표이동
	Vector = Vector * Matrix;          // 연산자 오버로딩으로 백터와 행렬 계산
	Matrix.Rotate(30);                 // 30도만큼 회전
	Vector = Vector * Matrix;          // 연산자 오버로딩으로 백터와 행렬 계산
	Matrix.Scale(2);                   // 크기를 2배 확대
	Vector = Vector * Matrix;          // 연산자 오버로딩으로 백터와 행렬 계산

	cout << fixed;
	cout.precision(0);                 //소수점을 제거하면서 정수값으로 좌표설정
	cout << "0,0에서 (3,5)만큼이동,30도회전,2배 확대했을때의 좌표값은: ";
	cout << Vector.Position[0] << "," << Vector.Position[1] << "입니다." << endl;

	UnitMat();
	tpMat();
	multiplyTransposeMat();
	multiplyMat();
	

}