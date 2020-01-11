#include<iostream>
#include<vector>

using namespace std;

int max(int a, int b)
{
	return a > b ? a : b;
}
/*
//���һ��λ���ܹ������ô���λ���������λ�ö��ܵ���
bool canJump(vector<int>& nums)
{
	int size = nums.size() - 1;
	int index = 0;
	for (int i = 0; i <=size; ++i)
	{
		if (i > index)
			return false;
		index = max(index, i + nums[i]);
	}
	return true;
}
*/

//��̬�滮
bool canJump(vector<int>& nums)
{
	int size = nums.size() - 1;
	for (int i = size - 1; i >= 0; --i)
	{
		if (size - i <= nums[i])
			size = i;
	}
	return size == 0;
}
int main()
{
	vector<int> nums{ 3,2, 1,0, 4 };
	cout<<canJump(nums);
	system("pause");
	return 0;
}