#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool isPalindrome(int x) {
	long long  sum = 0;
	int temp = x;
	while (temp / 10 != 0 || temp %10!=0)
	{
		int t = temp % 10;
		sum = t + sum * 10;
		temp = temp / 10;
	}

	printf("%d", sum);
}

int main()
{
	isPalindrome(121);
	system("pause");
	return 0;
}