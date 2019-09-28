#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	int firstUniqChar(string s) {
		int array[256] = { 0 };
		for (int i = 0; i < s.size(); ++i)
		{
			array[s[i]] ++;
		}
		for (int i = 0; i < s.size(); ++i)
		{
			if (array[s[i]] == 1)
			{
				return i;
			}
		}
		return -1;
	}
};

int main()
{
	Solution s;
	string p("loveleetcode");
	int i = s.firstUniqChar(p);
	cout << i;
	system("pause");
	return 0;
}