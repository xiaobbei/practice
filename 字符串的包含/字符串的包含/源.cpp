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

//��ϣ��+λͼ��˼��
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