#include<iostream>
#include<string>

using namespace std; 

bool StringContain(string &a,string &b)
{
	for(int i = 0 ;i<b.size();++i)
	{
		int j;
		for(j = 0;j<a.size() && (a[j]!=b[i]);++j)
			;
		if(j>=a.size())
			return false;
	}
	return true;
}
int main()
{
	string a,b;
	a = "ABCD";
	b = "BCD";
	cout<<StringContain(a,b);
	return 0;
}
