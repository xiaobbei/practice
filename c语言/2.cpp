#include<iostream>
#include<vector>

using namespace std;

void find_num_add(vector<int> v,int number)
{
	vector<int> res;
	for(int i = 0;i<number;++i)
	{
		for(int j = i+1;j<number;++j)
		{
			if(v[i] + v[j] == number)
			{
				res.push_back(i);
				res.push_back(j);
				break;
			}
		}
	}
	cout<<"���Թ��ɸ�Ԫ�ص�����Ϊ��"<<endl;
	for(int i = 0;i<res.size();++i)
		cout<<res[i]<<" ";
}
int main()
{
	int n;
	cout<<"���������봴������Ĵ�С:"<<endl; 
	while(cin>>n)
	{
		int number;
		vector<int> v(n);
		cout<<"����������Ԫ��,�Կո���"<<endl; 
		for(int i = 0;i<n;++i)
		{
			cin>>v[i];	
		} 
		cout<<"������������ҵ�Ԫ��"<<endl; 
		cin>>number;
		find_num_add(v,number);
		cout<<endl;
	}	
	return 0;
}
