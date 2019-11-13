#pragma warning(disable:4996)
#include<iostream>
#include<string>
#include<string.h>
using namespace std;

void replaceSpace(char *str, int length) {
	string s(str);
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == ' ')
		{
			s.erase(i, 1);
			s.insert(i, "%20");
		}
	}
	auto temp = s.c_str();
	strcpy(str, temp);
}
int main()
{
	char t[] = "we are happy ";
	char *p = t;
	replaceSpace(p, 10);
	for()z
	system("pause");
	return 0;
}