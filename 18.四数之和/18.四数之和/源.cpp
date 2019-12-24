#include<iostream>
#include<vector>
#include<algorithm>
using namespace  std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
	vector<vector<int>> res;
	sort(nums.begin(), nums.end());
	if (nums.size() < 4)
		return res;
	int l, r, sum;
	for (int i = 0; i < nums.size() - 3; ++i)
	{
		for (int j = i+1; j < nums.size() - 2; ++j)
		{
			l = j + 1;
			r = nums.size() - 1;
			while (l < r)
			{
				sum = nums[i] + nums[j] + nums[l] + nums[r];
				if (sum < target)
					l++;
				else if (sum>target)
					r--;
				else
				{
					res.push_back(vector<int>{nums[i], nums[j], nums[l], nums[r]});
					while (l < r && nums[l] == nums[l + 1])
						l++;
					while (l < r && nums[r] == nums[r - 1])
						r--;
					l++;
					r--;
				}
			}
			while (j + 1 < nums.size() - 2 && nums[j] == nums[j + 1])
				j++;
		}
		while (i + 1 < nums.size() - 3 && nums[i] == nums[i + 1])
			i++;
	}
	for (int i = 0; i < res.size(); ++i)
	{
		for (int j = 0; j < res[i].size(); ++j)
			cout << res[i][j] << " ";
		cout << endl;
	}
	return res;
}
int main()
{
	vector<int> nums{ 1, 0, -1, 0, -2, 2 };

	fourSum(nums, 0);
	system("pause");
	return 0;
}