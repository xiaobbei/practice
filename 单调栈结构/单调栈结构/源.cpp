/*
创建一个栈来存各个值的下标。
从左往右扫描数组，在将A[i]加入栈之前，将所有大于等于A[i]的元素出栈，此时栈顶元素就是左侧第一个小于A[i]的数的下标，
在记录答案之后将i入栈，继续向右扫描。
在此操作下，栈中元素一直保持单调递增，故称单调栈。

正确性证明：假设j < i是i左侧第一个满足A[j] < A[i]的数。
由假设可得，对于每个k(j < k < i)，都有A[k] >= A[i]，否则与假设矛盾。
这些数都会被i出栈，出栈之后栈顶元素就是j。

同理从右往左扫描即可求出右侧第一个小于A[i]的数的下标。
*/
#include<stack>
#include<iostream>
#include<vector>
using namespace std;

void Find_Min()
{
	vector<int> A;
	int n;
	cin >> n;
	int number;
	for (int i = 0; i < n; ++i)
	{
		cin >> number;
		A.push_back(number);
	}
	vector<int> L(n);
	vector<int> R(n);
	stack<int> s; //存放数据的下标
	for (int i = 0; i < n; ++i)
	{
		while (!s.empty() && A[s.top()] > A[i])
		{
			s.pop();
		}
		if (s.empty())
		{
			L[i] = -1;
		}
		else
			L[i] = s.top();
		s.push(i);  //存储下标
	}

	while (!s.empty())
	{
		s.pop();
	}
	for (int j = n - 1; j >= 0; --j)
	{
		while (!s.empty() && A[s.top()] > A[j])
			s.pop();
		if (s.empty())
		{
			R[j] = -1;
		}
		else
			R[j] = s.top();
		s.push(j);
	}
	for (int i = 0; i < n; ++i)
	{
		cout << L[i] << " " << R[i] << endl;
	}
}

int main()
{
	Find_Min();

	system("pause");
	return 0;
}