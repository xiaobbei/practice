#include<iostream>
#include<string>
using namespace std;

int titleToNumber(string s) {
	int n = s.size() - 1;//ָ��
	int res = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		res += pow(26, n)*(s[i] - 'A' + 1); //����ߵ�ָ���������n--
		n--;
	}
	return res;
}
int main()
{
	system("pause");
	return 0;
}