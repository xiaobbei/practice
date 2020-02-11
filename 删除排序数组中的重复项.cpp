#include<iostream>
#include<vector> 
using namespace std;
int removeDuplicates(vector<int>& nums) {
	if(nums.size()<=2)
		return nums.size();
	int index = 2;
	for(int i = 2;i<nums.size();++i)
	{
		if(nums[i]!=nums[index-2])
			nums[index++] = nums[i];
	}
	return index;
} 
int main()
{
	
	return 0;
 } 
