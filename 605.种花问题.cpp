#include<iostream>
#include<vector>

using namespace std;

bool canPlaceFlowers(vector<int>& flowerbed, int n) {
	int count = 1;
	for(int i = 0;i<flowerbed.size();++i)
	{
		if(flowerbed[i] == 0)
		{
			count++;
		}
		else
			count = 0;
		if(count == 3)
		{
			n--;
			count=1;
		}
	}
	if(count == 2)
		n--;
	return n>0?false:true;
}

int main()
{
	int a[] = {1,0,0,0,1};
	vector<int>flowerbed(a,a+sizeof(a)/sizeof(a[0]));
	int n;
	cin>>n;
	cout<<canPlaceFlowers(flowerbed,n);
	return 0;
} 
