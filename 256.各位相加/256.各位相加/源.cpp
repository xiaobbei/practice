#include<iostream>

using namespace std;

//������
int addDigits(int num) {
	int result = 0;
	while (num >= 10)
	{
		result = num % 10;
		num /= 10;
		num += result;
	}
	return num;
}

//�ҹ���O(1)
int addDigits_2(int num) {
	if (num>9)
	{
		num %= 9;
		if (num == 0)
			return 9;
	}
	return num;
}
int main()
{
	addDigits(100);
	system("pause");
	return 0;
}