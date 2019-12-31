#include<iostream>
#include<vector>

using namespace std;

void permuteCount(vector<vector<int>>& res, vector<int>& nums, int state)
{
	if (state == nums.size())
	{
		res.push_back(nums);
	}
	for (int j = state; j<nums.size(); j++){
		swap(nums[state], nums[j]);
		permuteCount(res, nums, state + 1);
		swap(nums[state], nums[j]);
	}
}
vector<vector<int>> permute(vector<int>& nums) {
	vector<vector<int>> res;
	permuteCount(res, nums, 0);
	return res;
}


int main()
{
	vector<int>nums{ 1, 2, 3 };
	permute(nums);
	system("pause");
	return 0;
}