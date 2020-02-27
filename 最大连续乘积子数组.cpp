#include<iostream>
#include<vector>

using namespace std; 

double MaxProductSubstring(vector<double> &a,int length)
{
	double maxRes = a[0];
	for(int i = 0; i<length;++i)
	{
		double x = 1;
		for(int j = i;j<length;++j)
		{
			x *= a[j];
			if(x>maxRes)
				maxRes = x;
		}
	}
	return maxRes;
}
int main()
{
	return 0;
}
