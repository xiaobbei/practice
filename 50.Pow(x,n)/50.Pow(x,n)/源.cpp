#include<iostream>
using namespace std;

double myPow(double x, int n){
	if (n == 0) return 1;
	if (n == 1) return x;
	if (n == -1) return 1 / x;
	double temp = myPow(x, n / 2);
	return temp * temp * myPow(x, n % 2);
}

int main()
{
	cout<<myPow(2, 2);
	system("pause");
	return 0;
}