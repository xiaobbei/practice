#include<iostream>

using namespace std;

int path(int n, int m)
{
	if (n > 1 && m > 1)
		return path(n - 1, m) + path(n, m - 1);
	else if ((n == 1) && (m >= 1) || (n >= 1) && (m == 1))
		return n + m;
	else
		return 0;
}
int main()
{
	int n, m;
	cin >> n >> m;
	cout << path(n, m);
	system("pause");
	return 0;
}