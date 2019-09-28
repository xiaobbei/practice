#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s;
	getline(cin, s);
	int i = s.rfind(' ') + 1;
	int sum = s.size() - i;
	cout << sum;
	system("pause");
	return 0;
}