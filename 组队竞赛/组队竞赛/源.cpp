#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int test()
{
	int n;
	cin >> n;
	vector<int> res(3*n);
	for (int i = 0; i < 3 * n; ++i)
	{
		cin >> res[i];
	}
	sort(res.begin(), res.end());
	int result = 0;
	for (int i = n; i < 3 * n-1; i + 2)
	{
		result += res[i];
	}
	return result;
}
int main()
{
	cout<< test();
	system("pause");
	return 0;
}