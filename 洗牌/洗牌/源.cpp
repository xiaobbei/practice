#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int T, n, k;//T�飬ÿ��2n�ţ�ϴk��
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
			//�����ǰ��С��n������������֣��´γ��ֵ�λ��Ϊ2*i
			//�����ǰλ��+n���������֣��´γ��ֵ�λ��Ϊ2*i+1
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