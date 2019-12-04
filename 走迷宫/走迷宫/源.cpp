#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> v;
vector<vector<int>> temp;
vector<vector<int>> bast;
int N, M;

void MazeTrack(int i, int j)
{
	v[i][j] = 1;
	temp.push_back({ i, j });
	if (i == N - 1 && j == M - 1)
	{
		if (bast.empty() || temp.size() < bast.size())
			bast = temp;
	}

	if (i - 1 >= 0 && v[i - 1][j] == 0)
		MazeTrack(i - 1, j);
	if (i + 1 < N && v[i + 1][j] == 0)
		MazeTrack(i + 1, j);
	if (j - 1 >= 0 && v[i][j - 1] == 0)
		MazeTrack(i, j - 1);
	if (j + 1 <M  && v[i][j + 1] == 0)
		MazeTrack(i, j + 1);

	v[i][j] = 0;
	temp.pop_back();
}
int main()
{

	while (cin >> N >> M)
	{
		v = vector<vector<int>>(N, vector<int>(M, 0));
		temp.clear();
		bast.clear();
		for (auto &i:v)
		for (auto &j : i)
			cin >> j;
		MazeTrack(0, 0);
		for (auto it : bast)
			cout << it[0] << it[1] << endl;
			
	}
	system("pause");
	return 0;
}