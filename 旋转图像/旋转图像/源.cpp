#include<iostream>
#include<vector>

using namespace std;

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
void rotate(vector<vector<int>>& matrix) {
	for (int i = 0; i < matrix.size(); ++i)
	{
		for (int j = i; j < matrix[i].size(); ++j)
		{
			swap(matrix[i][j], matrix[j][i]);
		}
	}
	for (int i = 0; i < matrix.size(); ++i)
	{
		for (int j = 0; j < matrix[i].size()/2; ++j)
		{
			swap(matrix[i][j], matrix[i][matrix.size() - j - 1]);
		}
	}
}

int main()
{
	vector<vector<int>> array{{ 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 }};
	rotate(array);
	for (int i = 0; i < array.size(); ++i)
	{
		for (int j = 0; j < array[i].size(); ++j)
			cout << array[i][j] << " ";
		cout << endl;
	}
	system("pause");
	return 0;
}