#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	int n,k;
	cout<<"������n �� k��ֵ:"; 
	while(cin>>n>>k)
	{
		int count = 0;
		vector<int> res(n+1);
		cout<<"������n����:";
		for(int i = 0;i<n;++i)
		{
			cin>>res[i];
		}
		sort(res.begin(),res.end());
		for(int i = 1;i<n;++i)
		{
			if(res[i] == res[i-1])
			{
				continue;
			}
			k--;
			if(k==0)
			{
				cout<<res[i]<<endl;
			}
		}
		if(k>0)
		{
			cout<<"NO RESULT"<<endl; 
		}
		cout<<"������n �� k��ֵ:"; 
	}
	return 0;
}
