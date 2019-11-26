#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;


/*
unordered_set<int> u;
vector<int> answer;
for(int i:nums1)
u.insert(i);
for(int i:nums2){
auto a = u.find(i);
if(a!=u.end()){
answer.push_back(i);
u.erase(a);
}
}
return answer;
*/
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
	vector<int> res;
	unordered_set<int> u;
	for (int i = 0; i < nums1.size(); ++i)
	{
		u.insert(nums1[i]);
	}
	for (int i = 0; i < nums2.size(); ++i)
	{
		auto it = u.find(nums2[i]);
		if (it != u.end())
		{
			res.push_back(nums2[i]);
			u.erase(nums2[i]);
		}
	}
	for (auto e : res)
		cout << e;
	return res;
}
int main()
{
	vector<int> nums1{ 1, 2, 2, 1 };
	vector<int> nums2{ 2, 2 };
	intersection(nums1, nums2);
	system("pause");
	return 0;
}