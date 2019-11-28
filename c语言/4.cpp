#include<iostream>
#include<string>
#include<algorithm>
using namespace std;



int main()
{
	int number,R;
	string R_table="0123456789ABCDEF";
	string s;
	bool flag = true;
	while(cin>>number>>R)
	{
		while(number)
		{
			s+=R_table[number%R];
			number/=R;
		}
		reverse(s.begin(),s.end());
		cout<<s<<endl;
	}
	return 0;
 } 
