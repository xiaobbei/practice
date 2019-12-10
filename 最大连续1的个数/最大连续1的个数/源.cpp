#include<iostream>
#include<vector>

using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
	int max = 0;
	int temp = 0;
	int i = 0;
	while (i<nums.size())
	{
		temp = 0;
		while (i<nums.size() && nums[i] == 1)
		{
			i++;
			temp++;
		}
		if (max<temp)
			max = temp;
		i++;
	}
	return max;
}
int main()
{
	vector<int> v{ 1, 1, 0, 1, 1, 1 };
	cout << findMaxConsecutiveOnes(v);
	system("pause");
	return 0;
}