/* 
����һ���������飬����Ҫ��ԭ��ɾ���ظ����ֵ�Ԫ�أ�ʹ��ÿ��Ԫ��ֻ����һ�Σ������Ƴ���������³��ȡ�

��Ҫʹ�ö��������ռ䣬�������ԭ���޸��������鲢��ʹ�� O(1) ����ռ����������ɡ�
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