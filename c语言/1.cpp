#include<iostream>

using namespace std;

int jump_count(int number)
{
	if(number == 1)
	{
		return 1;	
	}	
	if(number == 2)
	{
		return 2;
	}
	return jump_count(number-1)+jump_count(number-2);
}

int main()
{
	int n;
	cout<<"������¥��:"; 
	while(cin>>n)
	{
		cout<<jump_count(n)<<endl;
		cout<<"������¥��:"; 
	}
	return 0;
 } 
