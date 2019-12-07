#include<iostream>
#include<string>
#include<bitset>
using namespace std;


//暴力法
/*
void Compare(string s1, string s2)
{
	int i = 0, j = 0;
	for (i = 0; i < s2.size(); ++i)
	{
		for (j = 0; j < s1.size(); ++j)
		{
			if (s1[j] == s2[i])
				break;
		}
		if (j >= s1.size())
		{
			cout << "false" << endl;
			return;
		}
	}
	cout << "true" << endl;
}
*/


void Compare(string s1, string s2)
{
	bitset<26> r;
	for (int i = 0; i < s1.size(); ++i)
	{
		r.set(s1[i] - 'A');
	}
	for (int i = 0; i < s2.size(); ++i)
	{
		if (r.test(s2[i]-'A') != 0)
		{
			cout << "false" << endl;
			return;
		}
	}
	cout << "true" << endl;
}
int main()
{
	string s1, s2;
	cout << "s1为长串" << endl;
	while (cin>>s1>>s2)
	Compare(s1, s2);
	system("pause");
	return 0;
}