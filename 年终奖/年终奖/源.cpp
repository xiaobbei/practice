#include<iostream>
#include<vector>

using namespace std;

int max(int a, int b)
{
	return a > b ? a : b;
}

int getMost(vector<vector<int> > board) {
	vector<vector<int>> res(board.size(), vector<int>(board[0].size(), 0));
	res[0][0] = board[0][0];
	for (int i = 1; i<6; ++i)
	{
		res[0][i] = res[0][i - 1] + board[0][i];
	}
	for (int i = 1; i<6; ++i)
	{
		res[i][0] = res[i - 1][0] + board[i][0];
	}


	for (int i = 1; i<6; ++i)
	{
		for (int j = 1; j<6; ++j)
		{
			res[i][j] = max(res[i - 1][j], res[i][j - 1]) + board[i][j];
		}
	}
	return res[5][5];
}

int main()
{
	vector<vector<int>>v(6, vector<int>(6, 0));
	for (int i = 0; i < 6; ++i)
	{
		for (int j = 0; j < 6; ++j)
			cin >> v[i][j];
	}
	cout << getMost(v);
	system("pause");
	return 0;
}