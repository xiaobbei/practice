#include<iostream>

using namespace std;

/*使用快慢指针的思想，快指针走两步，慢指针走一步，当快慢指针相等时，表示一次循环结束
	:n = 4
	slow: 16 37 58 89 145 42 20  4 跳出循环
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