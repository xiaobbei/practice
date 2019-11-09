#include<iostream>

using namespace std;

int main()
{
	int num1, num2, num3, num4;
	int A, B, C;
	cin >> num1 >> num2 >> num3 >> num4;
	A = (num1 + num3) / 2;
	B = (num2 + num4) / 2;
	C = (num4 - num2) / 2;
	if ((A - B == num1) && (B - C == num2) && (B + A == num3) && (B + C == num4))
		cout << A << " " << B << " " << C;
	else
		cout << "No";
	system("pause");
	return 0;
}