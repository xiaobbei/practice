/*
����һ���������飬ʵ��һ�����������������������ֵ�˳��
ʹ�����е�����λ�������ǰ�벿�֣����е�ż��λ��λ������ĺ�벿�֣�
����֤������������ż����ż��֮������λ�ò��䡣
*/

/*
����˼·��
	����һ�����飬ͨ�����ϵ�push_back��Ԫ�ؽ���β���ȥ
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	void reOrderArray(vector<int> &array) {
		vector<int> res;
			if (array.empty())
			{
				return;
			}
		for (int i = 0; i<array.size(); ++i)
		{
			if (array[i] % 2 == 1)
			{
				res.push_back(array[i]);
			}
		}
		for (int i = 0; i<array.size(); ++i)
		{
			if (array[i] % 2 == 0)
			{
				res.push_back(array[i]);
			}
		}
		array = res;
	}
};
int main()
{
	system("pause");
	return 0;
}