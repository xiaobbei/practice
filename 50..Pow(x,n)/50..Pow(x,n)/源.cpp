/*����˼·��
**ʹ���۰���㣬ÿ�ΰ�n��Сһ�룬����n���ջ���С��0���κ�����0�η���Ϊ1��
**����ʱ����x��ż��ֱ�ӳ���һ�ε��м���
**���սṹ��Ҫ�Է��Ž����ж�
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