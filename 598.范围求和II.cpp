#include<iostream>
#include<vector>
using namespace std;

int maxCount(int m, int n, vector<vector<int> >& ops)
{
	int minx = m;
	int miny = n;
	for(auto it:ops)
    {
        if(minx>it[0])
            minx = it[0];
        if(miny>it[1])
            miny = it[1];
    }
    return minx*miny;
}
int main()
{
	vector<vector<int> > ops(4,vector<int>(4,0));
	for(int i = 0;i<4;++i)
	{
		for(int j = 0;j<4;++j)
			cin>>ops[i][j];
	}
	cout<<maxCount(3,3,ops);
	return 0;
}
