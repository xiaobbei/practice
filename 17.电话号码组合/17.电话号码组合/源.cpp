#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

void func(vector<string>& res, string str, string& digits, unordered_map<char, string>& table, int k)
{
	if (str.size() == digits.size())
	{
		res.push_back(str);
		return;
	}
	string temp = table[digits[k]];
	for (char w : temp)
	{
		str += w;
		func(res, str, digits, table, k + 1);
		str.pop_back();
	}
	return;
}
vector<string> letterCombinations(string digits) {
	unordered_map<char, string> table{
		{ '0', " " }, { '1', "*" }, { '2', "abc" }, { '3', "def" }, { '4', "ghi" },
		{ '5', "jkl" }, { '6', "mno" }, { '7', "pqrs" }, { '8', "tuv" }, { '9', "wxyz" }};

	vector<string> res;
	if (digits == "")
		return res;
	func(res, "", digits, table, 0);
	return res;
}
int main()
{

	system("pause");
	return 0;
}