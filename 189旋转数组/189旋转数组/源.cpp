#include<iostream>
#include<vector>
using namespace std;

//��һ�����鱣����kλ���飬��ǰ�����������ƶ�kλ����д��ǰ�������
void rotate(vector<int>& nums, int k) {
		if (k >= nums.size())
			k %= nums.size();
		if (k != 0)
		{
			vector<int> a(k);
			int idx = 0;
			for (int i = nums.size() - k; i < nums.size(); i++)//������kλ����
			{
				a[idx] = nums[i];
				idx++;
			}
			idx = 0;
			for (int i = nums.size() - k - 1; i >= 0; i--)//��ǰ�������ƶ�kλ
			{
				nums[nums.size() - 1 - idx] = nums[i];
				idx++;
			}
			for (int i = 0; i < k; i++)//����kλ����д��
			{
				nums[i] = a[i];
			}
		}
	
}

//��һ����С��ͬ���������ƶ������ȷλ�ã���д��ԭ������

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
	�������Ϊ�����֣���Ϊ0����nums.size()-k-1��nums.size()-k����nums.size()-1;
	�����ֱַ�ת�������巴ת�����ܵõ���ȷ�Ľ����
	���ӣ�[1, 2, 3, 4, 5, 6, 7] �� k = 3
	��Ϊ[1, 2, 3, 4]��[5, 6, 7]; �ֱ�ת��õ�[4, 3, 2, 1, 7, 6, 5]
	�����巴ת��[5, 6, 7, 1, 2, 3, 4] ��Ϊ��ȷ�ý��
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