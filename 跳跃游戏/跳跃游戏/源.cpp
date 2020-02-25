#include<iostream>

#include<vector>
using namespace std;


int min(int a, int b)
{
	return a > b ? b : a;
}
bool canJumpFunc(int index, vector<int>& nums)
{
	if (index == nums.size())
		return true;
	int Jump = min(index + nums[index], nums.size());
	for(int i = index + 1; i < Jump; ++i)
	{
		if (canJumpFunc(i, nums))
			return true;
	}
	return false;
}
//»ØËÝ·¨
bool canJump(vector<int>& nums)
{
	return canJumpFunc(0, nums);
}
int main()
{
	vector<int> array{3, 2, 1, 0, 4};
	cout << canJump(array);
	system("pause");
	return 0;
}