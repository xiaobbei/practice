#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void ReverseString(string& s)
{
	reverse(s.begin(),s.end());
	int state = 0,end = 0;
	for(int i = 0;i<s.size();++i)
	{
		while(i<s.size() && s[i] == ' ')
			i++;
		state = end = i;
		while(i<s.size() && s[i] != ' ')
		{
			end++;
			i++;
		}
		reverse(s.begin() + state,s.begin() + end);
	}
	reverse(s.begin(),s.end());
	cout<<s<<endl;
}
int main()
{
	string s;
	while(getline(cin,s))
	{
		ReverseString(s);
	}
	return 0;
}
