/*
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

注意：给定 n 是一个正整数。

解题思路：
	费波拉契数列
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

/*int climbStairs(int n) {  // 递归实现，因为递归时间复杂度非常高，不建议采用
	if (n <= 0)
	{
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}
	if (n == 2)
	{
		return 2;
	}
	return climbStairs(n - 1) + climbStairs(n - 2);
}*/

int climbStairs(int n) {
	if (n == 0)
	{
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}
	if (n == 2)
	{
		return 2;
	}
	int num_1 = 1;
	int num_2 = 2;
	for (int i = 2; i < n; ++i)
	{
		int temp = num_2;
		num_2 = num_2 + num_1;
		num_1 = temp;
	}
	return num_2;
}


int main()
{
	int n;
	scanf("%d", &n);
	int i = climbStairs(n);
	printf("%d", i);
	system("pause");
	return 0;
}