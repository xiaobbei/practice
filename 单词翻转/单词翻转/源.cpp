#include<iostream>
#include<string>


using namespace std;

//先将整体反转，最终再逐个反转
void Remove(string& s, int left, int right)
{
	while (left < right)
	{
		swap(s[left], s[right]);
		left++;
		right--;
	}
}
int main()
{
	string s;
	while (getline(cin,s))
	{
		Remove(s, 0, s.size() - 1);
		int start = 0,end = 0;
		int i = 0;
		while(i<s.size())
		{
			while (i < s.size() && s[i] == ' ')
				i++;
			start = end = i;
			while (i < s.size() && s[i] != ' ')
			{
				i++;
				end++;
			}
			Remove(s, start, end - 1);
		}
		cout << s << endl;
	}
	system("pause");
	return 0;
}