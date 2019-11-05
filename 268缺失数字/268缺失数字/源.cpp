#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int missingNumber(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size(); ++i)
	{
		if (nums[i] != i)
			return i;
	}
	return nums.size();  //当nums为[0]时返回1，所以这块返回nums.size()；
}


int missingNumber_2(vector<int>& nums) {
	int sum = nums.size();
	for (int i = 0; i < nums.size(); ++i)
	{
		sum ^= i^nums[i];
	}
	return sum;
}
int main()
{
	int a[] = { 9,6,4,2,3,5,7,0,1 };
	vector<int> nums(a, a + sizeof(a) / sizeof(a[0]));
	cout << missingNumber_2(nums);
	system("pause");
	return 0;
}