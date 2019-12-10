#include<iostream>
#include<vector>
using namespace std;
 

int min(int a, int b)
{
	return a > b ? b : a;
}
int minimumTotal(vector<vector<int>> &triangle) {
	if (triangle.empty())
		return false;
	vector<vector<int>>dp(triangle);
	int line = triangle.size();
	for (int i = 1; i < triangle.size(); ++i)
	{
		dp[i][0] = dp[i - 1][0] + triangle[i][0];
		dp[i][i] = dp[i - 1][i - 1] + triangle[i][i];
	}
	for (int i = 2; i < triangle.size(); ++i)
	{
		for (int j = 1; j < i; ++j)
		{
			dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];
		}
	}

	int Min = dp[triangle.size() - 1][0];
	for (int i = 1; i < triangle.size(); ++i)
	{
		if (Min > dp[triangle.size() - 1][i])
			Min = dp[triangle.size() - 1][i];
	}
	return Min;
}
int main()
{
	vector<vector<int>> triangle{ { 2 }, { 3, 4 }, { 6, 5, 7 }, { 4, 1, 8, 3 } };
	cout << minimumTotal(triangle) << endl;
	system("pause");
	return 0;
}