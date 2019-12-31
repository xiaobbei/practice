/*解题思路：
**使用折半计算，每次把n缩小一半，这样n最终会缩小到0，任何数的0次方都为1，
**奇数时乘上x，偶数直接乘上一次的中间结果
**最终结构需要对符号进行判断
*/

#include<iostream>

using namespace std;

double myPow(double x, int n) {
	double res = 1.0;
	for (int i = n; i != 0; i /= 2)
	{
		if (i % 2 != 0)
			res *= x;
		x*=x;
	}
	return n > 0 ? res : 1 / res;
}
int main()
{
	cout<<myPow(2, 3) << endl;
	system("pause");
	return 0;
}