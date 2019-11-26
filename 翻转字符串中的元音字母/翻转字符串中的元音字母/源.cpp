#include<iostream>
#include<string>
#include<set>

using namespace std;

/*
string reverseVowels(string s)
{
	string str = "aeiouAEIOU";
	int i = 0;
	int j = s.size() - 1;
	while (i < j) {
		while (i < j && (str.find(s[i]) == -1)) i++;
		while (i < j && (str.find(s[j]) == -1)) j--;
		swap(s[i++], s[j--]);
	}
	return s;
}
*/

string reverseVowels(string s)
{
	set<char> se;
	se.insert('a');
	se.insert('e');
	se.insert('i');
	se.insert('o');
	se.insert('u');
	se.insert('A');
	se.insert('E');
	se.insert('I');
	se.insert('O');
	se.insert('U');
	int i = 0, j = s.size() - 1;
	while (i < j)
	{
		while (i < j && !(se.find(s[i]) != se.end()))
			i++;
		while (i < j && !(se.find(s[j]) != se.end()))
			j--;
		swap(s[i++], s[j--]);
	}
	return s;
}
int main()
{
	cout << reverseVowels("leetcode");
	system("pause");
	return 0;
}