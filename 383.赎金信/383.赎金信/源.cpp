#include<iostream>
#include<string>
#include<map>
using namespace std;


bool canConstruct(string ransomNote, string magazine) {
	map<char, int>Mymap;
	for (auto it : magazine)
		Mymap[it]++;
	for (auto it : ransomNote)
	{
		if (Mymap[it]-- == 0)
			return false;
	}
	return true;
}
int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		cout<< canConstruct(s1, s2) << endl;
	}
	system("pause");
	return 0;
}