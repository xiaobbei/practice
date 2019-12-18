#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> matriReshape(vector<vector<int>> nums,int r,int c)
{
	int sum = 0;
	for(auto it:nums)
		sum+=it.size();
	if(sum<(r*c))
		return nums;
	vector<int> temp;
	vector<vector<int>> res(r,vector<int>(c,0));
	for(int i = 0;i<nums.size();++i)
	{
		for(int j = 0;j<nums[i].size();++j)
		{
			temp.push_back(nums[i][j]);
		}
	}

	int count = 0;
	for(int i = 0;i<r;++i)
	{
		for(int j = 0;j<c;++j)
			res[i][j] = temp[count++];
	}

	return res;	
}
int main()
{
	matriReshape(nums,r,c);
	return 0;
}
