#include<iostream>
#include<vector>

using namespace std;

int findUnsortedSubarry(vector<int>& nums)
{
	int len = nums.size();
    int max = nums[0];
    int min = nums[len-1];
    int l = 0, r = -1;
    for(int i=0;i<len;i++){
        if(max>nums[i]){
            r = i;
        }else{
            max = nums[i];
        }
        if(min<nums[len-i-1]){
            l = len-i-1;
        }else{
            min = nums[len-i-1];
        }
    }
    return r-l+1;
}
int main()
{
	int a[] = {2,6,4,8,10,9,15};
	vector<int> nums(a,a+7);
	cout<< findUnsortedSubarry(nums);
	return 0;
}
