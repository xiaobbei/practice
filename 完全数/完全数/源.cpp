#include<iostream>

using namespace std;

bool isPerfectnumber(int number)
{
	int sum = 0;
	for (int i = 1; i<number; ++i)
	{
		if (number%i == 0)
			sum += i;
	}
	return (sum == number);
}
int main()
{
	int n;
	cin >> n;
	int count = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (isPerfectnumber(i))
		{
			count++;
		}
	}
	cout << count;
	system("pause");
	return 0;
}