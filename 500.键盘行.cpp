#include<iostream>
#include<vector>
#include<string> 

using namespace std;

void findwords(vector<string>& words)
{
	vector<string> res;
	string s1 = "qwertyuiopQWERTYUIOP";
	string s2 = "asdfghjklASDFGHJKL";
	string s3 = "zxcvbnmZXCVBNM";
	for(int i = 0;i<words.size();++i)
	{
	 	int a = 0,b = 0,c = 0;
        for(int j = 0;j<words[i].size();++j)
        {
            if(s1.find(tolower(words[i][j]))!=string::npos) a++;
            if(s2.find(tolower(words[i][j]))!=string::npos) b++;
            if(s3.find(tolower(words[i][j]))!=string::npos) c++;
        }
        if(a == words[i].size() || b == words[i].size() || c == words[i].size())
            res.push_back(words[i]);
	}
	for(int i = 0;i<res.size();++i)
		cout<<res[i]<<" ";
}

int main()
{

	vector<string> words;
	for(int i = 0;i<3;++i)
	{
		string temp;
		cin>>temp;
		words.push_back(temp);
	}
	findwords(words);
	return 0;
}
