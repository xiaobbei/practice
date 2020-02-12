#include<iostream>
#include<string>
using namespace std;

string Del_str(string& s1,string s2)
{
    for(int i =0;i<s2.size();++i)
    {
        int index;
        while(s1.find(s2[i])!=-1)
        {
            index = s1.find(s2[i]);
            s1.erase(index,1);
        }
    }
    return s1;
}
int main()
{
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    Del_str(s1,s2);
    cout<<s1<<endl;
    return 0;
}
