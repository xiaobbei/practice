#include<iostream>
#include<assert.h>
using namespace std;

bool IsYear(int year, int Month)
{
	if (Month >= 2)
	{
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
			return true;
	}
	return false;
}

int dataToDay(int year, int Month, int Day)
{
	int a[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 };
	int sum = 0;
	if (IsYear(year, Month))
	{
		sum += 1;
	}
	for (int i = 1; i<Month; ++i)
	{
		sum += a[i];
	}
	sum += Day;
	return sum;
}
int main()
{
	int year, Month, Day;
	while (cin >> year >> Month >> Day)
	{
		cout << dataToDay(year, Month, Day) << endl;
	}
	system("pause");
	return 0;
}