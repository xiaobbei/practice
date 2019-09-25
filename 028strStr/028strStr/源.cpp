/*
����һ�� haystack �ַ�����һ�� needle �ַ�����
�� haystack �ַ������ҳ� needle �ַ������ֵĵ�һ��λ�� (��0��ʼ)��
��������ڣ��򷵻�  -1��
*/

#include<iostream>
#include<string>
using namespace std;

/* ���ÿ⺯������ѯ
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