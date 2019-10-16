#include<iostream>
#include<vector>
using namespace std;

vector<int> getRow(int rowIndex) {
	vector<vector<int>> temp(rowIndex+1);
	for (int i = 0; i<=rowIndex; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			if (j == 0 || j == i)
				temp[i].push_back(1);
			else
				temp[i].push_back(temp[i - 1][j - 1] + temp[i-1][j]);
		}
	}
	for (int i = 0; i <= rowIndex; ++i)

	{
		for (int j = 0; j <= i; ++j)
			cout << temp[i][j];
		cout << endl;
	}

	vector<int>res;
	for (int i = 0; i <= rowIndex; ++i)
	{
		int t = temp[rowIndex][i];
		res.push_back(t);
	}
	return res;
}

int main()
{
	getRow(3);
	system("pause");
	return 0;
}