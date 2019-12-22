#include<iostream>
#include<string>
#include<vector>
using namespace std;

/*暴力法
string intToRoman(int num)
{
	string res = "";
	while (num>0)
	{
		if (num >= 1000)
		{
			res += 'M';
			num -= 1000;
		}
		else if (num >= 900)
		{
			res += 'C';
			res += 'M';
			num -= 900;
		}
		else if (num >= 500)
		{
			res += 'D';
			num -= 500;
		}
		else if (num >= 400)
		{
			res += 'C';
			res += 'D';
			num -= 400;
		}
		else if (num >= 100)
		{
			res += 'C';
			num -= 100;
		}
		else if (num >= 90)
		{
			res += 'X';
			res += 'C';
			num -= 90;
		}
		else if (num >= 50)
		{
			res += 'L';
			num -= 50;
		}
		else if (num >= 40)
		{
			res += 'X';
			res += 'L';
			num -= 40;
		}
		else if (num >= 10)
		{
			res += 'X';
			num -= 10;
		}
		else if (num >= 9)
		{
			res += 'I';
			res += 'X';
			num -= 9;
		}
		else if (num >= 5)
		{
			res += 'V';
			num -= 5;
		}
		else if (num >= 4)
		{
			res += 'I';
			res += 'V';
			num -= 4;
		}
		else
		{
			res += 'I';
			num -= 1;
		}
	}
	return res;
}
*/

//贪心法
string intToRoman(int num)
{
	string res;
	vector<int> numbre = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
	vector<string> str = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
	int storeSize = int(numbre.size());
	for (int i = 0; i < storeSize; ++i)
	{
		while (num >= numbre[i])
		{
			res.append(str[i]);
			num -= numbre[i];
		}
	}
	return res;
}

int main()
{
	int num;
	while (cin >> num)
	{
		cout << intToRoman(num) << endl;
	}
	return 0;
}