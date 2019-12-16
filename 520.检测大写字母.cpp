#include<iostream>
#include<string>
using namespace std;
int IsBigStr(char w)
{
	if(w>='A' && w<='Z')
		return 1;
	return -1;
}

bool detectCapitalUse(string& word)
{
	int sum1 = 0;
	int sum2 = 0;
	for(int i = 0;i<word.size();++i)
	{
		if(IsBigStr(word[i]) == 1)
				sum1++;
		else
			sum2++;
	}
	if(sum1 == word.size() || sum2 == word.size())
		return true;
	if(sum1 == 1 && IsBigStr(word[0]) == 1)
		return true;
	return false;
}
int main()
{
	string word;
	while(cin>>word)
	{
		cout<<detectCapitalUse(word)<<endl;
	}
	return 0;
}
