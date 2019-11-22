#include<iostream>
#include<string>

using namespace std;

int StrToInt(string str)
{
	
	if (str.empty())
		return 0;
	int symbol = 1;
	if (str[0] == '-') //处理负号
	{
		symbol = -1;
		str[0] = '0'; //这里是字符'0',不是0
	}
	else if (str[0] == '+') //处理正号
	{
		symbol = 1;
		str[0] = '0';
	}
	int sum = 0;
	for (int i = 0; i<str.size(); ++i)
	{
		if (str[i] >= '0'&&str[i] <= '9')
			sum = sum * 10 + symbol*(str[i] - '0');
	}
	return sum;
}
int main()
{
	string s = "-2147483649";
	cout<< StrToInt(s);
	system("pause");
	return 0;
}