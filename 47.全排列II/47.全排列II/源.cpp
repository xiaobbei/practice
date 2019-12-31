/**解题思路：
**：先对元素进行排序，在回溯法+剪枝法
**：剪枝法：i>0 && nums[i] == nums[i - 1] && visited[i - 1] == 0
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void permuteUniqueCount(vector<vector<int>>& res, vector<int>& nums, vector<int>& temp, vector<int>& visited)
{
	if (temp.size() == nums.size())
		res.push_back(temp);
	for (int i = 0; i < nums.size(); ++i)
	{
		if (visited[i] != 0)   //值为1，表示该元素在temp中，直接跳过
			continue;
		if (i>0 && nums[i] == nums[i - 1] && visited[i - 1] == 0)  //如果前后两个元素值相同，并且前一个值没在temp中，表示有可能有多个相同的元素
			continue;
		visited[i] = 1;
		temp.push_back(nums[i]);
		permuteUniqueCount(res, nums, temp, visited);
		temp.pop_back();
		visited[i] = 0;
	}
}
vector<vector<int>> permuteUnique(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	vector<vector<int>> res;
	vector<int> temp;
	vector<int> visited(nums.size(), 0 );
	permuteUniqueCount(res, nums, temp, visited);
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
	vector<int> nums{ 1, 1, 2 };
	permuteUnique(nums);
	system("pause");
	return 0;
}