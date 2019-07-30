#include<stdio.h>
#include<stdlib.h>

int reverse(int x)
{
	long long sum = 0;
	while (x % 10 != 0 || x / 10 != 0)
	{
		int temp = x % 10;
		sum = temp + sum * 10;
		if (sum > INT_MAX || sum < INT_MIN)
		{
			return 0;
		}
		x = x / 10;
	}
	return sum;
}
int main()
{
	int i = reverse(123);
	printf("%d", i);
	system("pause");
	return 0;
}