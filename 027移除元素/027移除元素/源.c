/*
	����һ������ nums ��һ��ֵ val������Ҫԭ���Ƴ�������ֵ���� val ��Ԫ�أ������Ƴ���������³��ȡ�
	���� nums = [0,1,2,2,3,0,4,2], val = 2,

	����Ӧ�÷����µĳ��� 5, ���� nums �е�ǰ���Ԫ��Ϊ 0, 1, 3, 0,4
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