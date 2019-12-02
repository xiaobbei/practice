#include<iostream>
#include<string>
using namespace std;

int main()
{
	int n;
	string s;
	while (cin >> n >> s)
	{
		int num = 1, first = 1;
		if (n <= 4)
		{
			for (int i = 0; i < s.size(); ++i)
			{
				if (num == 1 && s[i] == 'U')
					num = n;
				else if (num == n && s[i] == 'D')
					num = 1;
				else if (s[i] == 'U')
					num--;
				else
					num++;
			}
			for (int i = 1; i < n; ++i)
			{
				cout << i << " ";
			}
			cout << first << endl;
		}
		else
		{
			for (int i = 0; i < s.size(); ++i)
			{
				if (first == 1 && num == 1 && s[i] == 'U')
				{
					first = n - 3;
					num = n;
				}
				else if (first == n - 3 && num == n &&s[i] == 'D')
				{
					first = 1;
					num = 1;
				}
				else if (first != 1 && num == first &&s[i] == 'U')
				{
					first--;
					num--;
				}
				else if (first != n - 3 && num == first + 3 && s[i] == 'D')
				{
					first++;
					num++;
				}
				else if (s[i] == 'U')
				{
					first--;
					num--;
				}
				else 
				{
					first++;
					num++;
				}
			}
			for (int i = first; i <= first + 3; ++first)
			{
				cout << i << " ";
			}
			cout << first << endl;
		}
	}
	system("pause");
	return 0;
}