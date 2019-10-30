#include<iostream>
#include<string>
using namespace std;

bool isStr_num(char c)
{
	return (c >= 'A'&&c <= 'Z') || (c >= 'a'&&c <= 'z') || (c >= '0'&&c <= '9');
}
bool isPalindrome(string s) {
	for (auto& e : s)						// 先将字符统一的转换为小写，然后再比较
	{
		if (e >= 'A'&&e <= 'Z')
			e += 32;
	}
	int left = 0;
	int right = s.size() - 1;
	while (left<right)
	{
		while (left<right && !isStr_num(s[left]))
			left++;
		while (left<right && !isStr_num(s[right]))
			right--;
		if (s[left] != s[right])
			return false;
		else
		{
			left++;
			right--;
		}
	}
	return true;
}
int main()
{
	system("pause");
	return 0;
}