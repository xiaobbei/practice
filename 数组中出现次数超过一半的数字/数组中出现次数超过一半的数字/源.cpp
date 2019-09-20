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
		//判断出现的次数是否大于其数组长度的一半，
		int n = 0;   //这块不能用count来判断出现的次数，因为上面count--,导致count的数据不准确
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


