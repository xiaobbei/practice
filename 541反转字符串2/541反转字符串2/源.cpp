#include<iostream>
#include<string>
using namespace std;


void reverse(string& s, int left, int right)
{
	char c;
	while (left < right)
	{
		c = s[left];
		s[left] = s[right];
		s[right] = c;
		left++;
		right--;
	}
}
string reverseStr(string s, int k) {
	int i = 0;
	int j = k;
	int end = s.size();
	while (i<end - 1)
	{
		j = i + k;
		if (j > end)
			j = end;
		reverse(s, i, j - 1);
		i += 2 * k;
	}
	return s;
}

void reverse_1(string& s, int i, int j)
{
	char c;
	while (i<j)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
		i++;
		j--;
	}
}
string reverseStr_1(string& s, int k) {
	int i = 0;
	int j = k;
	int len = s.size() - 1;
	while (i < len)
	{
		j = i + k;
		if (j >= len)
			j = len;
		reverse(s, i, j);
		i += 2 * k;
	}
	return s;
}

int main()
{
	string s("abcdasdsadsadewead");
	reverseStr_1(s, 4);
	cout << s;
	system("pause");
	return 0;
}