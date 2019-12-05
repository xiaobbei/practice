#include<iostream>
#include<string>
using namespace std;

/*
//������
void Remove(string& s,int size)
{
	char temp = s[0];
	for (int i = 1; i < size; ++i)
	{
		s[i - 1] = s[i];
	}
	s[size - 1] = temp;
}

int main()
{
	string s;
	int n, size;
	cout << "����һ���ַ���" << endl;
	while (cin >> s)
	{
		cout << "�����ַ�����ת�Ĵ�����";
		cin >> n;  
		size = s.size();
		while (n--)
		{
			Remove(s,size);
		}
		cout << s << endl;
	}
	system("pause");
	return 0;
}
*/


//������ת
//���ַ���Ϊ�����֣��Ƚ�ǰ�벿�ַ�ת���ٽ���벿��ת���������巴ת

void Remove(string& s, int left, int right)
{
	while (left < right)
	{
		swap(s[left], s[right]);
		left++;
		right--;
	}
}
int main()
{
	string s;
	int n;
	while (cin >> s)
	{
		cin >> n;
		Remove(s,0,n-1);
		Remove(s, n, s.size() - 1);
		Remove(s, 0, s.size() - 1);
		cout << s << endl;
	}
	system("pause");
	return 0;
}