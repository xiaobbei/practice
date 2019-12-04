#include<iostream>
#include<string>

using namespace std;

int Get_root(int sum)
{
	if (sum <10)
		return sum;
	int temp = 0;
	while (sum>0)
	{
		temp += sum % 10;
		sum /= 10;
	}
	if (temp > 10)
		return Get_root(temp);
	return temp;
}

int main()
{
	string s;
	while (cin >> s)
	{
		int sum = 0;
		for (int i = 0; i<s.size(); ++i)
			sum += s[i] - '0';
		sum = Get_root(sum);
		cout << sum << endl;
	}
	system("pause");
	return 0;
}