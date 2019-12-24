#include<iostream>
#include<string>
#include<vector>

using namespace std;

//l为左括号数，r为右括号数，
/*
	bfs + 剪枝法
	左括号的数目一旦小于右括号的数目，以及，左括号的数目和右括号数目均小于n
*/
void func(vector<string>& res, string str, int l, int r, int n)
{
	if (l > n || r > n || r > l)
		return;
	if (l == n &&r == n)
	{
		res.push_back(str);
		return;
	}
	func(res, str + '(', l + 1, r, n);
	func(res, str + ')', l, r + 1, n);
	return;
}
vector<string> generateParenthesis(int n) {
	vector<string> res;
	func(res, "", 0, 0, n);
	for (int i = 0; i < res.size(); ++i)
	{
		for (int j = 0; j < res[0].size(); ++j)
			cout << res[i][j] << " ";
		cout << endl;
	}
	return res;
}
int main()
{
	generateParenthesis(3);
	system("pause");
	return 0;
}