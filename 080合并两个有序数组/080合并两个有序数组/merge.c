#include<stdio.h>


void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
	int i = 0;
	int p, q;
	for (p = m; p < nums1Size; ++p)
	{
		nums1[p] = nums2[i];
		i++;
	}
	for (q = 0; q < p; q++)
	{
		for (i = 0; i < p - q - 1; ++i)
		{
			if (nums1[i] > nums1[i + 1])
			{
				int temp = nums1[i];
				nums1[i] = nums1[i + 1];
				nums1[i + 1] = temp;
			}
		}
	}
}


int main()
{
	int nums1[6] = { 4,1,2 };
	int nums2[3] = { 3,5,6 };
	merge(nums1, 6, 3, nums2, 3, 3);
	for (int i = 0; i < 6; ++i)
	{
		printf("%d ", nums1[i]);
	}
	system("pause");
	return 0;
}