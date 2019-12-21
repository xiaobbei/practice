#include<iostream>
#include<vector>

using namespace std;

int max(int a,int b)
{
	return a>b?a:b;
}
int min(int a,int b)
{
	return a>b?b:a;
}
/*暴力法
int maxArea(vector<int>height)
{
	int Max = 0;
	for(int i = 0;i<height.size();++i)
	{
		for(int j = i;j<height.size();++j)
		{
			Max = max(Max,min(height[j],height[i])*(j-i));
		}
	}
	return Max;
}
*/

int maxArea(vector<int> height)
{
	int Max = 0;
	int left = 0,right = height.size()-1;
	while(left<right)
	{
		Max = max(Max,min(height[left],height[right])*(right-left));
		if(height[left]<height[right])
			left++;
		else
			right--;
	}
	return Max;
}
int main()
{
	
	int a[]= {1,8,6,2,5,4,8,3,7};
	int t = sizeof(a)/sizeof(a[0]);
	vector<int> height(a,a+t);
	cout<<maxArea(height);
	return 0;
}
