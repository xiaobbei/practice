/*
������������¥�ݡ���Ҫ n ������ܵ���¥����

ÿ��������� 1 �� 2 ��̨�ס����ж����ֲ�ͬ�ķ�����������¥���أ�

ע�⣺���� n ��һ����������

����˼·��
	�Ѳ���������
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

/*int climbStairs(int n) {  // �ݹ�ʵ�֣���Ϊ�ݹ�ʱ�临�Ӷȷǳ��ߣ����������
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