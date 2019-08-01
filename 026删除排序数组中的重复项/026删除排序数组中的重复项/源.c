/* 
给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。

不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
*/

#include<stdio.h>
#include<stdlib.h>


int removeDuplicates(int* nums, int numsSize) {
	if (numsSize == 0)
	{
		return 0;
	}
	int count = 1;
	int cur = nums[0];
	for (int i = 1; i < numsSize; ++i)
	{
		if (nums[i] != cur)
		{
			nums[count] = nums[i];
			cur = nums[i];
			count++;
		}
	}
	return count;
}

int main()
{
	int a[] = { 1,1,2 };
	int size = sizeof(a) / sizeof(a[0]);
	int j = removeDuplicates(a, size);
	
	system("pause");
	return 0;
}