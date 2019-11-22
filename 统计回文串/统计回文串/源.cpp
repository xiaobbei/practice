#include<iostream>
#include<string>

using namespace std;


bool IsCircleText(const string& s)
{
	int begin = 0;
	int end = s.size() - 1;
	while (begin < end)
	{
		if (s[begin] != s[end])
			return false;
		begin++;
		end--;
	}
	return true;
}
int main()
{
	string a, b;
	getline(cin, a);
	getline(cin, b);

	int count = 0;
	for (int i = 0; i <= a.size(); ++i)
	{
		string str = a;
		str.insert(i,b);
		if (IsCircleText(str))
			count++;
	}
	cout << count;
	system("pause");
	return 0;
}

