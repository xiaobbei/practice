#include<iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int num1 = 0;
	int num2 = 1;
	int temp;
	while (1)
	{
		if (n >= num1 && n <= num2)
		{
			int min = 0;
			if ((n - num1) > (num2 - n))
			{
				min = (num2-n);
				cout << min;
				break;
			}
			else
			{
				min = (n - num1);
				cout << min;
				break;
			}
		}
		temp = num1 + num2;
		num1 = num2;
		num2 = temp;
	}
	system("pause");
	return 0;
}