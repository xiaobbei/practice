/*����һ�����������һ��Ŀ��ֵ�����������ҵ�Ŀ��ֵ�������������������Ŀ��ֵ�������������У����������ᱻ��˳������λ�á�
����: [1,3,5,6], 5
���: 2

����: [1,3,5,6], 2
���: 1

����: [1,3,5,6], 7
���: 4

����: [1,3,5,6], 0
���: 0
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