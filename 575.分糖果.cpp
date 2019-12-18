#include<iostream>
#include<vector>
#include<set>

using namespace std;

int distributeCandies(vector<int> candies)
{
	set<int> s;
    for(auto it:candies)
        s.insert(it);
    int temp = candies.size()/2;
    if(temp<s.size())
        return temp;
    return s.size();    
}
int main()
{
	vector<int> nums;
    for(int i = 0;i<6;++i)
		cin>>nums[i];
	cout<< distributeCandies(nums);
	return 0;
}
