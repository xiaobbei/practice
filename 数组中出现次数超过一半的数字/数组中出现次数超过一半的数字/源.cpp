#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		int cur = numbers[0];
		int count = 1;
		for (int i = 0; i < numbers.size(); ++i)
		{
			if (count != 0)
			{
				if (cur == numbers[i])
				{
					count++;
				}
				else
				{
					count--;
				}
			}
			else 
			{
				cur = numbers[i];
				count = 1;
			}
		}
		//�жϳ��ֵĴ����Ƿ���������鳤�ȵ�һ�룬
		int n = 0;   //��鲻����count���жϳ��ֵĴ�������Ϊ����count--,����count�����ݲ�׼ȷ
		for (int i = 0; i < numbers.size(); ++i)
		{
			if (cur == numbers[i])
			{
				n++;
			}
		}
		if (n > numbers.size() / 2)
		{
			return cur;
		}
		return 0;
	}
};


