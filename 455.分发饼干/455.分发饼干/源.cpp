#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int findContentChildren(vector<int>& g, vector<int>& s) {
	sort(g.begin(), g.end());
	sort(s.begin(), s.end());
	int count = 0;
	for (int i = g.size() - 1, j = s.size() - 1; i >= 0 && j >= 0; --i)
	{
		if (s[j] >= g[i])
		{
			j--;
			count++;
		}
	}
	return count;
}
int main()
{
	vector<int> g{ 1, 2, 3 };
	vector<int> s{ 1, 1 };
	cout << findContentChildren(g, s) << endl;
	system("pause");
	return 0;
}