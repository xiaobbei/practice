#include<iostream>
#include<string>
using namespace std;

//����ȥ������Ŀո� 
int lengthOfLastWord(string s) {
	int res = 0, i = s.size()-1;
	while(i>=0 && s[i] == ' ')
		i--;
	while(i >=0 )
	{
		if(s[i] == ' ')
			return res;
		else
			res++;
		i--;
	}
	return res;
}
int main()
{

	return 0;
 } 
