#include<iostream>
#include<string>
#include <algorithm>
using namespace std;



int main()
{
	string str;
	while (getline(cin, str))
	{
		reverse(str.begin(), str.end());
		int i = 0, j = i;
		while (i < str.size())
		{
			while (i < str.size() && str[i] == ' ')
				i++;
			j = i;
			while (i < str.size() && str[i] != ' ')
				++i;
			reverse(str.begin() + j, str.begin() + i);
		}
		cout << str << endl;
	}
	system("pause");
	return 0;
}