#include<iostream>

using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		int count = 0;
		while (n >= 3)
		{
			n = n - 2;
			count++;
		}
		if (n == 2)
			count++;
		cout << count << endl;
	}
	system("pause");
	return 0;
}