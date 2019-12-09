#include<iostream>

using namespace std;
int pick;

int guess(int n)
{
	if (n == pick)
		return 0;
	else if (n > pick)
		return -1;
	else
		return 1;
}
int guessNumber(int n) {
	int l = 1;
	int r = n;
	while (l <= r)
	{
		int mid = l + (r - l) / 2;
		if (guess(mid) == 0)
			return mid;
		else if (guess(mid) > 0)
			l = mid + 1;
		else
			r = mid - 1;
	}
	return 0;
}
int main()
{
	
	int n;
	
	while (cin >> n>>pick)
	{
		cout << guessNumber(n) << endl;
	}
	system("pause");
	return 0;
}