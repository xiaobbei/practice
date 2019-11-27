#include<iostream>
#include<vector>
using namespace std;



//n总人数，k报数间隔，s开始下标

void ysf_cir(int n, int k, int s)
{
	int count = 0;
	int say_num = 1;
	vector<int> res(n);
	for (int i = 0; i < n; ++i)
	{
		res[i] = i;
	}

	while (count < n)
	{
		say_num = 1;
		while (say_num < k)
		{
			s = (s + 1) % n;
			if (res[s]!=-1)
				say_num++;
		}
		count++;
		res[s] = -1;

		if (count < n)
		{
			while (res[s] == -1)
				s = (s + 1) % n;
		}
	}
}
int main()
{
	ysf_cir(6, 3, 2);
	system("pause");
	return 0;
}