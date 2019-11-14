#include<iostream>
#include<string>
using namespace std;
class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
		// write code here
		if (n % 2 != 0)
			return false;
		int count = 0;
		for (int i = 0; i<A.size(); ++i)
		{
			if (A[i] != '('&&A[i] != ')')
				return false;
			if (A[i] == '(')
				count++;
			if (A[i] == ')')
				count--;
		}
		if (count == 0)
			return true;
		return false;
	}
};

int main()
{
	system("pause");
	return 0;
}