#include<iostream>

using namespace std;

bool isPerfectSquare(int num) {
	int temp = sqrt(num);
	if (temp*temp == num)
		return true;
	return false;
}

int main()
{
	int n;
	while (cin >> n)
	{
		cout<< isPerfectSquare(n) << endl;
	}
	system("pause");
	return 0;
}