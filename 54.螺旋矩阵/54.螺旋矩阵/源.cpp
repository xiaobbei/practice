#include<iostream>
#include<vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
	vector<int> res;
	if (matrix.empty())
		return res;
	//�����������ұ߽�
	int u = 0;	//���к�
	int d = matrix.size() - 1;//���к�
	int l = 0; //���к�
	int r = matrix[0].size() - 1;//���к�
	while (1)
	{
		for (int i = l; i <= r; i++)
			res.push_back(matrix[u][i]);
		if (++u > d)
			break;
		for (int i = u; i <= d; ++i)
			res.push_back(matrix[i][r]);
		if (--r < l)
			break;
		for (int i = r; i >= l; --i)
			res.push_back(matrix[d][i]);
		if (--d < u)
			break;
		for (int i = d; i >= u; --i)
			res.push_back(matrix[i][l]);
		if (++l >r)
			break;
	}
	for (int i = 0; i < res.size(); ++i)
	{
			cout << res[i] << " ";
	}
	cout << endl;
	return res;
}
int main()
{
	vector<vector<int>> nums{ { 1, 2, 3 },{ 4, 5, 6 },{7,8,9} };
	spiralOrder(nums);
	system("pause");
	return 0;
}