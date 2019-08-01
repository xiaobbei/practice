/*
	给定一个数组 nums 和一个值 val，你需要原地移除所有数值等于 val 的元素，返回移除后数组的新长度。
	给定 nums = [0,1,2,2,3,0,4,2], val = 2,

	函数应该返回新的长度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0,4
*/

#include<stdio.h>
#include<stdlib.h>


int removeElement(int* nums, int numsSize, int val) {
	int count = 0;
	for (int i = 0; i < numsSize; ++i)
	{
		if (nums[i] != val)
		{
			nums[count] = nums[i];
			count++;
		}
	}
	return count;
}

int main()
{
	int a[] = { 0,1,2,2,3,0,4,2 };
	int size = sizeof(a) / sizeof(a[0]);
	int i = removeElement(a, size,2);
	for (int j = 0; j < i; ++j)
	{
		printf("%d",a[j]);
	}
	printf("%d", i);
	system("pause");
	return 0;
}