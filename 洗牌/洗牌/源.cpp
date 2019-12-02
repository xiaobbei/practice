#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int T, n, k;//T组，每组2n张，洗k次
	cin >> T;
	while (T--)
	{
		cin >> n >> k;
		int num = 2 * n;
		vector<int> table(num);
		for (int i = 0; i < num; ++i)
			cin >> table[i];
		while (k--)
		{
			vector<int> n1(table.begin(), table.end());
			//如果当前数小于n，则代表在左手，下次出现的位置为2*i
			//如果当前位置+n代表在右手，下次出现的位置为2*i+1
			for (int i = 0; i < n; ++i)
			{
				table[2 * i] = n1[i];
				table[2 * i + 1] = n1[n + i];
			}
		}
		for (int i = 0; i < num - 1; ++i)
			cout << table[i] << " ";
		cout << table[num - 1] << endl;
	}
	system("pause");
	return 0;
}