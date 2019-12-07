#include<iostream>
using namespace std;

int main()
{
	double n, r;
	while (cin >> n >> r)
	{
		if (n <= 2 * 3.14*r)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	system("pause");
	return 0;
}