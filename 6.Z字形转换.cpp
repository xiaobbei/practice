#include<iostream>
#include<vector>
#include<string>

using namespace std;
string convert(string s,int numRows)
{
	if(numRows == 1)
        return s;
    vector<string> rows(numRows);
    int curRow = 0;
    bool flag = false;

    for(int i = 0;i<s.size();++i)
    {
        rows[curRow] += s[i];
        if(curRow == 0 || curRow == numRows - 1)
            flag = !flag;
        curRow += flag?1:-1;
    }
    string res;
    for(int i = 0;i<rows.size();++i)
        res+=rows[i];
    return res;
}

int main()
{
	string s;
	while(cin>>s)
	{
		int num;
		cin>>num;
		cout<<convert(s,num);
	}
	return 0;
}

