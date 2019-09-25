#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
	bool isPalindrome(string s) {
		toLowerCase(s);
		int i = 0, j = s.size() - 1;
		while (i < j)
		{
			//isalnum�������ж��Ƿ�Ϊ��ĸ�������֣����Ϊ�棬���ط�0�����Ϊ�٣�����0
			while (i < j && isalnum(s[i])== 0)
				i++;
			while (i < j && isalnum(s[j])==0) //���Ϊ���Ż�ո�λ��+1
				j--;
			if (s[i] != s[j])
				return false;
			i++;
			j--;
		}
		return true;
	}
	void toLowerCase(string &s)
	{
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] >= 'A'&&s[i] <= 'Z')
			{
				s[i] += 32;
			}
		}
	}
};
int main()
{
	string s;
	Solution p;
	s = "A man, a plan, a canal: Panama";
	p.isPalindrome(s);
	system("pause");
	return 0;
}