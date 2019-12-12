#include<iostream>

using namespace std;

/*
   int findComplement(int num)
   {
   unsigned int n = num;
   while(n&(n-1)!=0)
   n&=(n-1);
   n=(n<<1)-1;
   return n^num;
   }*/

int findComplement(int num)
{
	long n = 1;
	while(n<=num)
		n=n<<1;

	return (int)(n-1)^num;
}


int main()
{
	int num;
	cin>>num;
	cout<<findComplement(num)<<endl;

	return 0;
}
