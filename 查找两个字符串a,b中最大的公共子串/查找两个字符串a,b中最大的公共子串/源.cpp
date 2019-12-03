#include<iostream>
#include<string>
#include<vector>

//¶¯Ì¬¹æ»®
using namespace std;
int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		if (s1.size() > s2.size())
			swap(s1, s2);
		int size1 = s1.size(), size2 = s2.size();
		vector<vector<int>> v(size1 + 1, vector<int>(size2 + 1, 0));
		int start = 0, max = 0;
		for (int i = 1; i <= size1; ++i)
		{
			for (int j = 1; j<= size2; ++j)
			{
				if (s1[i - 1] == s2[j - 1])
				{
					v[i][j] = v[i - 1][j - 1] + 1;
				}
				if (v[i][j] > max)
				{
					max = v[i][j];
					start = i - max;
				}
			}
		}
		cout << s1.substr(start, max) << endl;
	}
	system("pause");
	return 0;
}