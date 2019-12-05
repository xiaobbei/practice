#include<iostream>
#include<string>

using namespace std;

bool Find_string_contain(string A, string B)
{
	for (int i = 0; i < A.size(); ++i)
	{
		int j;
		for (j = 0; j < B.size(); ++j)
		{
		}
		if (j >= A.size())
			return false;
	}
	return true;
}

int main()
{
	string A, B;
	while (cin >> A >> B)
	{
		cout << Find_string_contain(A, B) << endl;
	}
	system("pause");
	return 0;
}