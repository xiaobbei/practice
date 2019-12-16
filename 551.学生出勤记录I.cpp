#include<iostream>
#include<string> 

using namespace std;

bool checkRecord(string s) {
    s.insert(s.begin(),'P');
    s.push_back('P');
    int count1 = 0;
    int count2 = 0;
    for(int i = 1;i<s.size();++i)
    {
        if(s[i] == 'A')
            count1++;
        if(s[i-1] == 'L' && s[i] == 'L' && s[i+1] == 'L')
            count2=1;
    }
    if(count1 <=1 && count2 ==0)
        return true;
    return false;
}

int main()
{
	string s;
	cin>>s;
	cout<<checkRecord(s);
	return 0;
}
