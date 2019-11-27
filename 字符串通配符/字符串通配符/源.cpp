#include<iostream>
#include<string>
using namespace std;


bool Is_str(const char* s1, const char* s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return true;
	if (*s1 == '\0' || *s2 == '\0')
		return false;
	if (*s1 == '?')
		return Is_str(s1 + 1, s2 + 1);
	else if (*s1 == '*')
		return Is_str(s1 + 1, s2) || Is_str(s1 + 1, s2 + 1);
	else if (*s1 == *s2)
		return Is_str(s1 + 1, s2 + 1);
	return false;
}
int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		if (Is_str(s1.c_str(), s2.c_str()))
			cout << true << endl;
		else
			cout << false << endl;
	}
	return 0;
}