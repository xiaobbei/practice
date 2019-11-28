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
	cout<<"可以构成该元素的索引为："<<endl;
	for(int i = 0;i<res.size();++i)
		cout<<res[i]<<" ";
}
int main()
{
	int n;
	cout<<"请输入你想创建数组的大小:"<<endl; 
	while(cin>>n)
	{
		int number;
		vector<int> v(n);
		cout<<"请输入数组元素,以空格间隔"<<endl; 
		for(int i = 0;i<n;++i)
		{
			cin>>v[i];	
		} 
		cout<<"请输入你想查找的元素"<<endl; 
		cin>>number;
		find_num_add(v,number);
		cout<<endl;
	}	
	return 0;
}
