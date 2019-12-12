#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

char upper(char c)
{
	if(c>='a' && c<='z')
		return c-'a'+'A';
	return c;
}
string licenseKeyFormatting(string s,int key)
{
	string res;
	int count = 0;
	for(int i = s.size()-1;i>=0;--i)
	{
		if(s[i]=='-')
			continue;
		res+=upper(s[i]);
		count++;
		if(count%key==0)
		{
			res+='-';
		}
	}
	count = res.size()-1;
	while(!res.empty() && res[count] =='-')
	res[count]='\0';
	reverse(res.begin(),res.end());
	return res;
}

int main()
{
	string s;
	int key;
	while(cin>>s>>key)
	{
		cout<<licenseKeyFormatting(s,key)<<endl;
	}
	return 0;
}

