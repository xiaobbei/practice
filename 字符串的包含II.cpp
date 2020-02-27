#include<iostream>
#include<algorithm>
#include<string>

using namespace std; 

bool StringContain(string &a,string &b)
{
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	for(int i = 0,j = 0;j<b.size();)
	{
		while((i<a.size()) && (a[i]<b[j]))
			i++;
		if(i>=a.size() || (a[i]>b[j]))
			return false;
		++j;
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
