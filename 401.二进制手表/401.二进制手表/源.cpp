#include<iostream>
#include<string>
#include<vector>
using namespace std;

//����ÿ��ʱ�䣬ͳ��ÿ��ʱ����1�ĸ����Ƿ��n��ֵһ���������n��ֵһ������浽�����С�
int count1(int i)  //�ж϶�������1 �ĸ���
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
			if (count1(i) + count1(j) == num)  //�ж�Сʱ+���Ӷ������е�1���Ƿ����num
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