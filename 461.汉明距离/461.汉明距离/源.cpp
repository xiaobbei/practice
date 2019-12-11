#include<iostream>

using  namespace std;

int hammingDistance(int x, int y) {
	int count = 0;
	int res = x^y;
	while (res != 0)
	{
		if (res & 1 == 1)
			count++;
		res >>= 1;
	}
	return count;
}

int main()
{
	int x, y;
	while (cin >> x >> y)
	{
		cout<< hammingDistance(x, y) << endl;
	}
	system("pause");
	return 0;
}