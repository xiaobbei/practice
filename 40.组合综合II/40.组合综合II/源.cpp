#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
	vector<vector<int>> res;
	vector<int> temp;;
	sort(candidates.begin(), candidates.end());
	combinationSum2Count(res, temp, candidates, target, 0);
	return res;
}

void combinationSum2Count(vector<vector<int>>& res, vector<int>& temp, vector<int>&candidates,
	int target, int start)
{
	if (0 == target)
	{
		res.push_back(temp);
		return;
	}
	if (target<0)
		return;
	for (int i = start; i<candidates.size(); ++i)
	{
		if (i>start && candidates[i] == candidates[i - 1])
			continue;
		temp.push_back(candidates[i]);
		combinationSum2Count(res, temp, candidates, target - candidates[i], i + 1);
		temp.pop_back();
	}
}

int main()
{

	system("pause");
	return 0;
}