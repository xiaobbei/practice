#include<iostream>
#include<vector>

using namespace std;

int max(int a, int b)
{
	return a > b ? a : b;
}
/*
//如果一个位置能够到达，那么这个位置左侧所有位置都能到达
bool canJump(vector<int>& nums)
{
	int size = nums.size() - 1;
	int index = 0;
	for (int i = 0; i <=size; ++i)
	{
		if (i > index)
			return false;
		index = max(index, i + nums[i]);
	}
	return true;
}
*/

//动态规划
bool canJump(vector<int>& nums)
{
	int size = nums.size() - 1;
	for (int i = size - 1; i >= 0; --i)
	{
		if (size - i <= nums[i])
			size = i;
	}
	return size == 0;
}
int main()
{
	vector<int> nums{ 3,2, 1,0, 4 };
	cout<<canJump(nums);
	system("pause");
	return 0;
}