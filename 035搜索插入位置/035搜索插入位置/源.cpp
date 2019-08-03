/*给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
输入: [1,3,5,6], 5
输出: 2

输入: [1,3,5,6], 2
输出: 1

输入: [1,3,5,6], 7
输出: 4

输入: [1,3,5,6], 0
输出: 0
*/

#include<iostream>
using namespace std;

int searchInsert(int* nums, int numsSize, int target) {
	int i;
	for (i = 0; i < numsSize; ++i)
	{
		if (nums[i] == target)
		{
			return i;
		}
	}
	for (i = 0; i < numsSize; ++i)
	{
		if (nums[i] > target)
		{
			return i;
		}
	}
	return i;
}
int main()
{
	int nums[] = { 1,3,5,6 };
	int size = (sizeof(nums)) / sizeof(nums[0]);
	int target;
	cin >> target;
	int i = searchInsert(nums, size, target);
	cout << i;
	system("pause");
	return 0;
}