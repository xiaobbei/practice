//斐波那契数列变形
/*	Floor                   方法
	number = 1  ---------->  1
	number = 2 ----------->  2
	number = 3 ----------->  3
*/
#include<iostream>

using namespace std;

int jumpFloor(int number)
{
	if (number == 1)
		return 1;
	if (number == 2)
		return 2;
	if (number == 3)
		return 3;
	return jumpFloor(number - 1) + jumpFloor(number - 2);
}

int jumpFloor_2(int number)
{
	if (number <= 2)
		return number;
	int Floor1 = 1;
	int Floor2 = 2;
	int temp = 0;
	for (int i = 3; i <= number; ++i)
	{
		temp = Floor1 + Floor2;
		Floor1 = Floor2;
		Floor2 = temp;
	}
	return Floor2;
}

int jumpFloor_3(int number)
{
	int arr[100];
	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 2;
	for (int i = 3; i <= number; ++i)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	return arr[number];
}
int main()
{
	cout<< jumpFloor_3(4);
	system("pause");
	return 0;
}