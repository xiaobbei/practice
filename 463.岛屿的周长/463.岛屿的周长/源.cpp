#include<iostream>
#include<vector>
using namespace std;

int islandPerimeter(vector<vector<int>>& grid) {
	int count = 0;
	for (int i = 0; i < grid.size(); ++i)
	{
		for (int j = 0; j < grid[0].size(); ++j)
		{
			if (grid[i][j] == 1)
			{
				count += 4;
				if (i>0 && grid[i - 1][j] == 1)
					count -= 1;
				if (i < grid.size() - 1 && grid[i + 1][j] == 1)
					count -= 1;
				if (j>0 && grid[i][j - 1] == 1)
					count -= 1;
				if (j < grid[0].size() - 1 && grid[i][j + 1] == 1)
					count -= 1;
			}
		}
	}
	return count;
}

int main()
{
	vector<vector<int>> grid = { { 0, 1, 0, 0 }, { 1, 1, 1, 0 }, { 0, 1, 0, 0 }, { 1, 1, 0, 0 } };
	cout << islandPerimeter(grid) << endl;
	system("pause");
	return 0;
}