#include<iostream>

using namespace std;

/*ʹ�ÿ���ָ���˼�룬��ָ������������ָ����һ����������ָ�����ʱ����ʾһ��ѭ������
	:n = 4
	slow: 16 37 58 89 145 42 20  4 ����ѭ��
	fast: 37 89 42 4  37  89 42  4
	:n = 19
	slow: 82 68 100 1 
	fast: 100 1  1  1 
*/
int Square_Add(int n)
{
	int res = 0;
	while (n)
	{
		int t = n % 10;
		res += (t*t);
		n /= 10;
	}
	return res;
}
bool isHappy(int n)
{
	if (n <= 0)
		return false;
	int slow = n, fast = n;
	do {
		slow = Square_Add(slow);
		fast = Square_Add(fast);
		fast = Square_Add(fast);
	} while (slow != fast);

	if (slow == 1)
		return true;
}
int main()
{
	isHappy_2(19);
	system("pause");
	return 0;
}