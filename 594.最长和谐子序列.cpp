#include<iostream>
#include<vector>
#include<map>
using namespace std; 

int findLHS(vector<int>& nums) 
{	
	map<int,int> m;
    int res = 0;
    for(int i = 0;i<nums.size();++i)
    {
        m[nums[i]]++;
    }
    vector<pair<int,int>> v;
    for(auto it:m)
    {
        v.push_back(pair(it.first,it.second));
    }
    for(int i = 1;i<v.size();++i)
    {
        if(v[i].first - v[i-1].first == 1)
        {
            res = max(res,v[i].second+v[i-1].second);  //.second相同元素个数 
        }
    }
    return res;
	
}
int main()
{
	int a[] ={1,3,2,2,5,2,3,7};
	cout<< vector<int> nums{a,a+8};
	return 0;
}
