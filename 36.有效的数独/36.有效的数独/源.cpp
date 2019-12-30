#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

/*
**解题思路
**：创建三个hash表，分别表示行，列，块中是否含有该元素
**：int index = (i/3)*3+j/3; index，计算块号，块号主要与行（i)相关
**：通过hash表的count函数进行查找
*/
bool isValidSudoku(vector<vector<char>>& board) {
	vector<unordered_map<int, int>> row(9), col(9), block(9);
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			int index = (i / 3) * 3 + j / 3;
			char cur = board[i][j];
			if (cur == '.')
				continue;
			if (row[i].count(cur) || col[j].count(cur) || block[index].count(cur))  return false;
			row[i][cur] = 1;
			col[j][cur] = 1;
			block[index][cur] = 1;
		}
	}
	return true;
}


int main()
{
	cout << 1 / 3 << endl;
	system("pause");
	return 0;
}