#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	string s, table= "0123456789ABCDEF";
	int m, n;
	cin >> m >> n;
	bool flag = false;
	if (m < 0)
	{
		m = 0 - m;
		flag = true;
	}
	while (m)
	{
		s += table[m%n];
		m /= n;
	}
	reverse(s.begin(), s.end());
	cout << s;
	system("pause");
	return 0;
}