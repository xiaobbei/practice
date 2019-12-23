#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
	sort(nums.begin(), nums.end());
	int res = nums[0] + nums[1] + nums[2];
	for (int i = 0; i < nums.size(); ++i)
	{
		int l = i + 1;
		int r = nums.size() - 1;
		while (l < r)
		{
			int sum = nums[i] + nums[l] + nums[r];
			if (abs(sum - target) < abs(res - target))
				res = sum;
			if (sum < target)
				l++;
			else if (sum>target)
				r--;
			else
				return target;
		}
	}
	return res;
}
int main()
{
	vector<int> nums{ -1, 2, 1, -4 };
	cout << threeSumClosest(nums, 1) << endl;
	system("pause");
	return 0;
}