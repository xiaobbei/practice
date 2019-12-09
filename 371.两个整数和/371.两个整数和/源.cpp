#include<iostream>

using namespace std;

int getSum(int a, int b) {
	while (b != 0)
	{
		int temp = (unsigned)(a&b) << 1;
		a ^= b;
		b = temp;
	}
	return a;
}
int main()
{
	int a, b;
	while (cin >> a >> b)
	{
		cout<< getSum(a, b) << endl;
	}
	system("pause");
	return 0;
}