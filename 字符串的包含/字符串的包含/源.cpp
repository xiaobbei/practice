#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
/*���������
bool String_Contain(string A, string B)
{
	for (int i = 0; i < B.size(); ++i)
	{
		int j;
		for (j = 0; j < A.size() && (A[j] != B[i]); ++j)  //ÿ�α���B�е��ַ���Ҫ��A����һ��
			;
		if (j >= A.size())
			return false;
	}
	return true;
}
*/


//�ȶ��ַ�����������
/*
bool String_Contain(string A, string B)
{
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	for (int i = 0, j = 0; j < B.size();++j)
	{
		while ((i < A.size()) && (A[i] < B[j])) 
			i++;
		if (i>=A.size() || A[i]>B[j])  //��������꣬����i�ҵ�A��ĩβ������A[i]>B[j]����ʾ������ַ��������ڣ���Ϊ�ַ�����
			return false;
	}
	return true;
}
*/

//�������
bool String_Contain(string A, string B)
{
	const int arr[26] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101 };
	int sum_A = 1;
	for (int i = 0; i < A.size(); ++i)
	{
		int temp = arr[A[i] - 'A'];
		if (sum_A%temp)   //��ͬ��Ԫ��ֻ����һ��
			sum_A *= temp;
	}
	for (int i = 0; i < B.size(); ++i)
	{
		int temp = arr[B[i] - 'A'];
		if (temp % sum_A)
		{
			return false;
		}
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