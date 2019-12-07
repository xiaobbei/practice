#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
/*暴力法求解
bool String_Contain(string A, string B)
{
	for (int i = 0; i < B.size(); ++i)
	{
		int j;
		for (j = 0; j < A.size() && (A[j] != B[i]); ++j)  //每次遍历B中的字符都要将A遍历一遍
			;
		if (j >= A.size())
			return false;
	}
	return true;
}
*/


//先对字符串进行排序
/*
bool String_Contain(string A, string B)
{
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	for (int i = 0, j = 0; j < B.size();++j)
	{
		while ((i < A.size()) && (A[i] < B[j])) 
			i++;
		if (i>=A.size() || A[i]>B[j])  //如果查找完，发现i找到A的末尾，或者A[i]>B[j]，表示后面的字符都不存在，因为字符有序
			return false;
	}
	return true;
}
*/

//哈希表+位图的思想
bool String_Contain(string A, string B)
{
	int hash = 0;
	for (int i = 0; i < A.size(); ++i)
	{
		hash |= (1 << A[i] - 'A');
	}

	for (int j = 0; j < B.size(); ++j)
	{
		if ((hash &(1 << B[j] - 'A')) == 0)
			return false;
	}
	return true;
}
int main()
{
	string A, B;
	while (cin >> A >> B)
	{
		cout << String_Contain(A, B) << endl;
	}
	system("pause");
	return 0;
}