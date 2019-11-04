#include<iostream>
#include<vector>
using namespace std;


int jumpFloorII(int number) {
	vector<int> res(number+1);
	res[0] = 0;
	res[1] = 1;
	res[2] = 2;
	int temp;
	for (int i = 3; i <= number; ++i)
	{
		temp = 0;
		for (int j = 0; j<i; ++j)
		{
			temp += res[j];
		}
		res[i] = temp + 1;
	}
	return res[number];
}


int main()
{
	cout<< jumpFloorII(4);
	system("pause");
	return 0;
}