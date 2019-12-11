#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


//先排序，找到最大的与最小的值
int minMoves(vector<int> nums) {
	sort(nums.begin(), nums.end());
	int count = 0;
	for (int i = 1; i < nums.size(); ++i)
	{
		int temp = (nums[i] + count) - nums[i - 1];
		nums[i] += count;
		count += temp;
	}
	return count;
}

int minMoves_I(vector<int> nums)
{
	sort(nums.begin(), nums.end());
	int count = 0;
	for (int i = 1; i < nums.size(); ++i)
	{
		count += nums[i] - nums[0];
	}
	return count;
}



int main()
{
	vector<int> res{ 83, 86, 77, 15, 93, 35, 86, 92, 49, 21};
	cout << minMoves(res) << endl;
	system("pause");
	return 0;
}