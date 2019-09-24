#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s;
	int num;
	cin >> num;
	char c;
	for (int i = 0; i < num; ++i)
	{
		cin >> c;
		s.push_back(c);
	}
	int count = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == 'L')
		{
			count += 1;
		}
		if (s[i] == 'R')
		{
			count += 3;
		}
	}
	switch (count % 4)
	{
	case 1:
		cout << 'W';
		break;
	case 2:
		cout << 'S';
		break;
	case 3:
		cout << 'E';
		break;
	case 0:
		cout << 'N';
		break;
	}
	system("pause");
	return 0;
}