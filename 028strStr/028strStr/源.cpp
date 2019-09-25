/*
给定一个 haystack 字符串和一个 needle 字符串，
在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。
如果不存在，则返回  -1。
*/

#include<iostream>
#include<string>
using namespace std;

/* 运用库函数，查询
class Solution {
public:
	int strStr(string haystack, string needle) {
		int pos = haystack.find(needle);
		return pos;
	}
};

int main()
{
	Solution s;
	string haystack, needle;
	haystack = "aaaaa";
	needle = "bba";
	int i = s.strStr(haystack, needle);
	cout << i;
	system("pause");
	return 0;
}

*/

class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle.empty())
		{
			return 0;
		}
		int i = 0, j = 0;
		while (haystack[i] != '\0' && needle[j] != '\0')
		{
			if (haystack[i] == needle[j])
			{
				i++;
				j++;
			}
			else
			{
				i = i - j + 1;
				j = 0;
			}
		}
		if (needle[j] == '\0')
		{
			return i - j;
		}
		return -1;
	}
};

int main()
{
	Solution s;
	string haystack, needle;
	haystack = "aaaaa";
	needle = "bba";
	int i = s.strStr(haystack, needle);
	cout << i;
	system("pause");
	return 0;
}