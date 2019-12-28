#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    map<string,vector<string> > ma;
    vector<vector<string>> res;
    for(auto str:strs){
        string tmp = str;
        sort(tmp.begin(),tmp.end());
        ma[tmp].push_back(str);
    }
    for(const auto& m:ma)
        res.push_back(m.second);
    return res;
}

int main()
{
	return 0;
}

