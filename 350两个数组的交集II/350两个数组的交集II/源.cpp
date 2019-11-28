#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
	vector<int> res;
	unordered_map<int, int> map;
	for (int i = 0; i < nums1.size(); ++i)
	{
		map[nums1[i]]++;
	}
	for (int i = 0; i < nums2.size(); ++i)
	{
		if (map(nums2[i])>0)
		{
			res.push_back(nums2[i]);
			map[nums2[i]]--;
		}
	}
	for (auto e : res)
		cout << e << " ";
	return res;
}

int main()
{
	vector<int>nums1{ 1, 2, 2, 1 };
	vector<int>nums2{ 2, 2 };
	intersect(nums1, nums2);
	system("pause");
	return 0;
}