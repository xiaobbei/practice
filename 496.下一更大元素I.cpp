#include<iostream>
#include<vector>
#include<map>
#include<stack>
using namespace std;



void  nextGreaterElement(vector<int>& nums1,vector<int>& nums2)
{
	map<int,int> mp;
    stack<int> s;
   	for(int i = 0;i<nums1.size();++i)
	   mp[nums1[i]] = -1; 
    for(int i = 0;i<nums2.size();++i)
    {
        while(!s.empty() && s.top()<=nums2[i])
        {
            mp[s.top()] = nums2[i];
            s.pop();              
        }
        s.push(nums2[i]);
    }
    for(int i = 0;i<nums1.size();++i)
    {
	    nums1[i] = mp[nums1[i]];
		cout<<nums1[i]<<" ";
	}
}

int main()
{
	int a[] = {2,4};
	int b[] = {1,2,3,4};
	vector<int>nums1(a,a+2);
	vector<int>nums2(b,b+4);
	nextGreaterElement(nums1,nums2);
	return 0;
}
