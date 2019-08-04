#include<iostream>
#include<string>
using namespace std;

//int lengthOfLastWord(string s) {
//	int length = 0;
//	for (int i = s.size() - 1; i >= 0; i--)
//	{
//		if (s[i] != ' ')
//		{
//			length++;
//		}
//		else if (s[i] == ' ')
//		{
//			return length;
//		}
//	}
//	return length;
//}

int lengthOfLastWord(char * s) {
	//int length = sizeof(s) / sizeof(s[0]);
	int length = 0;
	bool isWord = false;
	while (s[length] != '\0')
	{
		length++;
	}
	int size = 0;
	for (int i = length-1; i >= 0; --i)
	{
		if (s[i] != ' ')
		{
			size++;
			isWord = true;
		}
		else if (s[i] == ' '&& isWord)
		{
			return size;
		}
	}
	return size;
}

int main()
{
	char s[] = "H ";
	int i = lengthOfLastWord(s);
	printf("%d", i);
	system("pause");
	return 0;
}