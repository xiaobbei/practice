#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void arrayPairsum(vector<int> nums)
{
	sort(nums.begin(),nums.end());
    int sum = 0;
    for(int i = 0;i<nums.size();)
    {
        sum+=nums[i];
		i+=2;
	}
	cout<<sum;
}

int main()
{
	int a[] = {4,1,3,2};
	vector<int> nums(a,a+4);
	arrayPairsum(nums);
	return 0;
}
