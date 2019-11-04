#include<iostream>
#include<string>
#include<map>
using namespace std;

//利用计数排序的思想
bool isAnagram(string s, string t) {
	if (s.size() != t.size())
		return false;
	int arr1[256] = { 0 };
	int arr2[256] = { 0 };
	int size1 = s.size();
	int size2 = s.size();

	for (int i = 0; i<size1; ++i)
	{
		arr1[s[i]]++;
	}
	for (int i = 0; i<size2; ++i)
	{
		arr2[t[i]]++;
	}

	for (int i = 0; i<size1; ++i)
	{
		arr1[s[i]]--;
		arr2[s[i]]--;
	}

	for (int i = 0; i<size1; ++i)
	{
		if (arr1[s[i]] != 0 || arr2[t[i]] != 0)
			return false;
	}
	return true;
}
bool isAnagram_1(string s, string t) {
	if (s.size() != t.size())
		return false;
	map<int, int> m1;
	map<int, int> m2;
	for (auto e : s)
	{
		m1[e]++;
	}
	for (auto e : t)
	{
		m2[e]++;
	}
	for (int i = 0; i < s.size(); ++i)
	{
		m1[s[i]]--;
		m2[s[i]]--;
	}
	if (!m1.empty() || !m2.empty())
		return false;
	return true;

}
int main()
{
	string s("abc");
	string t("ab");
	isAnagram(s, t);
	system("pause");
	return 0;
}