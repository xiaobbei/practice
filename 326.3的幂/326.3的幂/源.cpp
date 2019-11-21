#include<iostream>

using namespace std;

bool IsPowisPowerOfThree(int n)
{
	if (n == 1)
		return true;
	long m = 1;
	while (m < n)
	{
		m *= 3;
		if (m == n)
		{
			return true;
		}
	}
	return false;
}

bool IsPowerOfThree_2(int n)
{
	if (n == 1)
		return true;
	else if (n == 0)
		return false;
	return IsPowerOfThree_2(n / 3) && (n % 3 == 0);
}
int main()
{
	int n;
	cin >> n;
	cout<<IsPowerOfThree_2(n);
	system("pause");
	return 0;
}