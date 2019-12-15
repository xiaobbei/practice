#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string convertToBase7(int num)
{
	string temp="0123456";
	string res;
	bool flag = false;
	if(num<0)
	{
		flag = true;
		num = 0- num;
	}
	while(num)
	{
		res+=temp[num%7];
		num/=7;
	}
	if(flag)
		res+='-';
	reverse(res.begin(),res.end());
	cout<<res;
	return res;
}

int main()
{
	int num;
	cin>>num;
	convertToBase7(num);
	return 0;
}
