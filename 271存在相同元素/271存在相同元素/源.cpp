#include<iostream>
#include<vector>
#include<map>
#include<set>

using namespace std;

//set
bool containsDuplicate(vector<int>& nums) {
	set<int> s;
	for (auto it : nums)
	{
		if (s.count(it) > 0)
			return true;
		else
			s.insert(it);
	}
	return false;
}

//map
bool containsDuplicate_2(vector<int>& nums) {
	map<int, int> m;//无序map更快
	for (int i = 0; i < nums.size(); i++)
	{
		if (m.count(nums[i]))
			return true;
		else
			m.insert(nums[i], i);
	}
	return false;
}

//暴力法

bool containsDuplicate_2(vector<int>& nums) {
	if (nums.size() <= 1)
		return false;
	for(int i = 0;i<nums.size();++i)
		for (int j = i + 1; j < nums.size(); ++j)
		{
			if (nums[i] == nums[j])
				return true;
		}
	return false;
}

int main()
{
	system("pause");
	return 0;
}