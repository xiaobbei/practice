#include<iostream>
#include<string>
using namespace std;

int titleToNumber(string s) {
	int n = s.size() - 1;//指数
	int res = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		res += pow(26, n)*(s[i] - 'A' + 1); //最左边的指数最大，所以n--
		n--;
	}
	return res;
}
int main()
{
	system("pause");
	return 0;
}