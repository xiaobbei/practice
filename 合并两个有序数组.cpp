#include<iostream>
#include<vector>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
   int last = m+n-1;
        while(n)
        {
            if(m == 0 || nums1[m-1] <= nums2[n-1])
                nums1[last--] = nums2[--n];
            else
                nums1[last--] = nums1[--m];
        }
	for(int i = 0;i<nums1.size();++i)
		cout<<nums1[i];
}

int main()
{
	int a[]={1,2,3};
	int b[]={3,4,5}; 
	vector<int> nums1(a,a+3);
	vector<int> nums2(b,b+3);
	merge(nums1,3,nums2,3);
	return 0;
}
