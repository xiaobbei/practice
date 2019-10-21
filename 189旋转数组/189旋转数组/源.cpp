#include<iostream>
#include<vector>
using namespace std;

//用一个数组保留后k位数组，将前面得数组向后移动k位，再写入前面得数组
void rotate(vector<int>& nums, int k) {
		if (k >= nums.size())
			k %= nums.size();
		if (k != 0)
		{
			vector<int> a(k);
			int idx = 0;
			for (int i = nums.size() - k; i < nums.size(); i++)//保留后k位数据
			{
				a[idx] = nums[i];
				idx++;
			}
			idx = 0;
			for (int i = nums.size() - k - 1; i >= 0; i--)//将前面数据移动k位
			{
				nums[nums.size() - 1 - idx] = nums[i];
				idx++;
			}
			for (int i = 0; i < k; i++)//将后k位数据写入
			{
				nums[i] = a[i];
			}
		}
	
}

//用一个大小相同得数组存放移动后得正确位置，再写入原数组中

void rotate_2(vector<int>& nums, int k) {
	if (k >= nums.size())
		k %= nums.size();
	if (k != 0)
	{
		vector<int> a(nums.size());
		for (int i = 0; i < nums.size(); ++i)
		{
			a[(i + k) % nums.size()] = nums[i];
		}
		for (int i = 0; i < nums.size(); ++i)
		{
			nums[i] = a[i];
		}
	}
}

/*
	将数组分为两部分，分为0——nums.size()-k-1和nums.size()-k——nums.size()-1;
	两部分分别反转，再整体反转，就能得到正确的结果。
	例子：[1, 2, 3, 4, 5, 6, 7] 和 k = 3
	分为[1, 2, 3, 4]和[5, 6, 7]; 分别反转后得到[4, 3, 2, 1, 7, 6, 5]
	再整体反转得[5, 6, 7, 1, 2, 3, 4] 即为正确得结果
*/

void rotate_3(vector<int>& nums, int k) {
	if (k >= nums.size())
		k %= nums.size();
	if (k != 0)
	{
		reversel(nums, 0, nums.size() - k - 1);
		reversel(nums, nums.size() - k, nums.size() - 1);
		reversel(nums, 0, nums.size() - 1);
	}
}
void reversel(vector<int>& a, int i, int j)
{
	while (i < j)
	{
		int temp = a[j];
		a[j] = a[i];
		a[i] = temp;
		i++;
		j--;
	}
}

int main()
{
	system("pause");
	return 0;
}