#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int n;
    vector<int> array(n);
    for(int i = 0;i<n;++i)
    {
        cin>>array[i];
    }
    int max = array[0];
    int sum = array[0]; 
    for(int i = 1;i<array.size();++i)
    {
        if(sum>=0)
			sum+=array[i];
		else
			sum = array[i];
		if(max<sum)
			max = sum; 
    }
    cout<<max<<endl;
    return 0;
}



