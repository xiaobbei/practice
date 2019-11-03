/*
����һ��ջ�������ֵ���±ꡣ
��������ɨ�����飬�ڽ�A[i]����ջ֮ǰ�������д��ڵ���A[i]��Ԫ�س�ջ����ʱջ��Ԫ�ؾ�������һ��С��A[i]�������±꣬
�ڼ�¼��֮��i��ջ����������ɨ�衣
�ڴ˲����£�ջ��Ԫ��һֱ���ֵ����������ʳƵ���ջ��

��ȷ��֤��������j < i��i����һ������A[j] < A[i]������
�ɼ���ɵã�����ÿ��k(j < k < i)������A[k] >= A[i]�����������ì�ܡ�
��Щ�����ᱻi��ջ����ջ֮��ջ��Ԫ�ؾ���j��

ͬ���������ɨ�輴������Ҳ��һ��С��A[i]�������±ꡣ
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
	stack<int> s; //������ݵ��±�
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
		s.push(i);  //�洢�±�
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