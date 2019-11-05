#include<iostream>
#include<string>
using namespace std;

void Del_equal(string s1, string s2)
{
	for (int i = 0; i < s2.size(); ++i)
	{
		int index;
		while ((index = s1.find(s2[i]))!=-1)
		{
			s1.erase(index, 1);
		}
	}
	cout << s1;
}
int main()
{
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	Del_equal(s1, s2);
	system("pause");
	return 0;
}