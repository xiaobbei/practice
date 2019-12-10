#include<iostream>
#include<string>
#include<vector>
using namespace std;

//遍历每个时间，统计每个时间中1的个数是否和n的值一样，如果和n的值一样，则存到容器中。
int count1(int i)  //判断二进制中1 的个数
{
	int res = 0;
	while (i != 0)
	{
		res++;
		i &= (i - 1);
	}
	return res;
}


vector<string> readBinaryWatch(int num) {
	vector<string> res;
	for (int i = 0; i < 12; ++i)
	{
		for (int j = 0; j < 60; ++j)
		{
			if (count1(i) + count1(j) == num)  //判断小时+分钟二进制中的1和是否等于num
			{
				res.push_back(to_string(i) + ":" + (j < 10 ? "0" + to_string(j) : to_string(j)));
			}
		}
	}
	return res;
}


int main()
{
	vector<string> res = readBinaryWatch(6);
	for (auto it : res)
		cout << it <<endl;
	system("pause");
	return 0;
}