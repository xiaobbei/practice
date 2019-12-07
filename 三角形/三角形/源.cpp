#include<iostream>

using namespace std;

int main()
{
	double a, b, c;
	while (cin >> a >> b >> c)
	{
		if (a > b)
			swap(a, b);
		if (a > c)
			swap(a, c);
		if (b > c)
			swap(b, c);
		if (a + b > c)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}