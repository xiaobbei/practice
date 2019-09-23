#include<iostream>

using namespace std;

int main()
{
	int left, right;
	cin >> left >> right;
	int count = 0;
	for (int i = left; i <= right; ++i)
	{
		switch (i % 3)
		{
		case 1:
			break;
		case 0:
			count++;
			break;
		case 2:
			count++;
			break;
		}
	}
	cout<<count;
	return 0;
}