#include<iostream>

using namespace std;

vector<vector<int>>res;
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    vector<int>r_res;
    process(0,nums,r_res);
    return res;
}
    void process(int start,vector<int>& nums,vector<int>& r_res){
    if(r_res.size()<=nums.size()){
        res.push_back(r_res);
        //return ;
    }
    for(int i=start;i<nums.size();i++){
        if(i!=start&&nums[i]==nums[i-1]) continue;
        r_res.push_back(nums[i]);
        process(i+1,nums,r_res);
        r_res.pop_back();
    }
}
int main()
{
	return 0;
 } 
