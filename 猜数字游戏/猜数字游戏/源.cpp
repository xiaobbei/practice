#include<iostream>
#include<string>
#include<vector>
using namespace std;


void getHint(string secret, string guess)
{
	vector<int> res;
	int A = 0;
	int B = 0;
	for (int i = 0; i < secret.size(); ++i)
	{
		if (secret[i] == guess[i])
		{
			A++;
			secret[i] = '*';
			guess[i] = '#';
		}
	}
	for (int i = 0; i < secret.size(); ++i)
	{
		int j = guess.find(secret[i]);
		if (j != guess.size() && guess[j] != '#')
		{
			B++;
			secret[i] = '*';
			guess[i] = '#';
		}
	}
	cout << A << "A" << B << "B";
}
int main()
{
	string secret, guess;
	cin >> secret >> guess;
	getHint( secret, guess);
	system("pause");
	return 0;
}