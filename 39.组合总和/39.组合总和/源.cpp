#include<iostream>
#include<vector>

using namespace std;


void combinationSumCount(vector<vector<int>>& res, vector<int>&temp, vector<int>&candidates, int target, int sum, int left)
{
	if (sum == target)
		res.push_back(temp);
	else
	{
		for (int i = left; i < candidates.size(); i++)
		{
			if (sum + candidates[i] <= target)
			{
				temp.push_back(candidates[i]);
				combinationSumCount(res, temp, candidates, target, sum + candidates[i], i);
				temp.pop_back();
			}
		}
	}
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	vector<vector<int>> res;
	vector<int> temp;
	combinationSumCount(res, temp, candidates, target, 0, 0);
	for (int i = 0; i < res.size(); ++i)
	{
		for (int j = 0; j < res[i].size(); ++j)
		{
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	return res;
}


int main()
{
	vector<int> candidates{ 2, 3, 6, 7 };

	combinationSum(candidates, 7);
	system("pause");
	return 0;
}