#include<iostream>
#include<vector>
using namespace std;

int rob(vector<int>& nums)
{
	int sum_even = 0;
	int sum_odd = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (i % 2 == 0)
		{
			sum_even += nums[i];
			sum_even = max(sum_even, sum_odd);
		}
		else
		{
			sum_odd += nums[i];
			sum_odd = max(sum_even, sum_odd);
		}
	}
	return max(sum_even, sum_odd);
}

int max(int a, int b)
{
	return a > b ? a : b;
}
int main()
{
	vector<int> a = { 2,7,9,3,1 };
	rob(a);
	system("pause");
	return 0;
}