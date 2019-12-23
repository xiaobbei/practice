#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int>> res;
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size() && nums[i] < 0; ++i)
	{
		if (i>0 && nums[i] == nums[i - 1])
			continue;
		int l = i + 1;
		int r = nums.size() - 1;
		while (l < r)
		{
			int sum = nums[i] + nums[l] + nums[r];
			if (sum < 0)
				l++;
			else if (sum>0)
				r--;
			else
			{
				res.push_back(vector<int>{nums[i], nums[l], nums[r]});
				l++;
				while (l < r && nums[l] == nums[l - 1])
					l++;
			}
		}
	}
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
	vector<int>nums{-1, 0, 1, 2, -1, -4};
	threeSum(nums);
	system("pause");
	return 0;
}