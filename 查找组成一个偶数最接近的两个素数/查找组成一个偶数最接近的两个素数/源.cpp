#include<iostream>
#include<vector>
using namespace std;

bool Is_sum(int x)
{
	for (int i = 2; i<x; ++i)
	{
		if (x%i == 0)
			return false;
	}
	return true;
}
int main()
{
	int num;
	cin >> num;
	vector<int> res;
	for (int i = 1; i <= num / 2; ++i)
	{
		if (Is_sum(i) && Is_sum(num - i))
		{
			res.push_back(i);
			res.push_back(num - i);
		}
	}
	cout << res[res.size() - 2] << endl;
	cout << res[res.size() - 1];
	system("pause");
	return 0;
}