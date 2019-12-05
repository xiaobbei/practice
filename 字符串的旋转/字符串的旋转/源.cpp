#include<iostream>
#include<string>
using namespace std;

/*
//暴力法
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
	cout << "输入一个字符串" << endl;
	while (cin >> s)
	{
		cout << "输入字符串旋转的次数：";
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


//三步反转
//将字符分为三部分，先将前半部分反转，再将后半部反转，最终整体反转

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