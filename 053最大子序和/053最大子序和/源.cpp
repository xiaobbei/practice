/*����һ���������� nums ���ҵ�һ���������͵����������飨���������ٰ���һ��Ԫ�أ������������͡�

����: [-2,1,-3, 4,-1,2,1,-5,4];
���: 6
����: ���������� [4,-1,2,1] �ĺ����Ϊ 6��
*/

#include<iostream>

using namespace std;

int max(int a, int b)
{
	return a > b ? a : b;
}
int maxSubArray(int* nums, int numsSize) {
	int res = INT_MIN;
	int sum = 0;
	for (int i = 0; i < numsSize; ++i)
	{
		sum = 0;
		for (int j = i; j < numsSize; ++j)
		{
			sum +=  nums[j];
			if (sum > res)
			{
				res = sum;
			}
		}
	}
	return res;
}


//��̬�滮˼��
/*
int maxSubArray(int* nums, int numsSize) {
	int res = INT_MIN;
	int sum = 0;
	for(int i =0;i<numsSize;++i)
	{
		sum = max(nums[i],sum+nums[i]);
		res = max(res,max);
	}
	return res;
}
*/
int main()
{
	int nums[] = { -2,1,-3,4,-1,2,1,-5,4 };
	int size = (sizeof(nums)) / (sizeof(nums[0]));
	int i = maxSubArray(nums, size);
	cout << i;
	system("pause");
	return 0;
}