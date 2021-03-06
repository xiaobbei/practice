#include<iostream>
#include<string>

using namespace std;


void ALL_count(string s, int left, int right)
{
	if (right <= 1)
		return;
	if (left == right)
	{
		for (int i = 0; i <= right; ++i)
		{
			cout << s[i];
		}
		cout << endl;
	}
	else
	{
		for (int i = left; i <= right; ++i)
		{
			swap(s[i], s[left]);
			ALL_count(s, left + 1, right);
			swap(s[i], s[left]);
		}
	}
}


int main()
{
	string a = "abc";
	ALL_count(a, 0, 2);
	system("pause");
	return 0;
}