#include<iostream>
#include<map>
#include<string>

using namespace std;

//Map实现
bool canConstruct(string ransomNote, string magazine) {
	map<char, int>Mymap;
	for (auto it : magazine)
		Mymap[it]++;
	for (auto it : ransomNote)
	{
		if (Mymap[it] == 0)
			return false;
		else
			Mymap[it]--;
	}
	return true;
}

//hashtable实现

bool canConstructII(string ransomNote, string magazine)
{
	if (ransomNote.size() > magazine.size())
		return false;
	int hashtable[26] = { 0 };
	for (int i = 0; i < magazine.size(); ++i)
	{
		hashtable[magazine[i] - 'a']++;
	}
	for (int i = 0; i < ransomNote.size(); ++i)
	{
		hashtable[ransomNote[i] - 'a']--;
		if (hashtable[ransomNote[i] - 'a'] == 0)
			return false;
	}
	return true;
}

int main()
{

	return 0;
}