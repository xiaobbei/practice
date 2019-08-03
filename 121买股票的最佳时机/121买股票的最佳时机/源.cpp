/*
给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。

如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。

注意你不能在买入股票前卖出股票。

输入: [7,1,5,3,6,4]
输出: 5
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。

解题思路：因为其不能在买入股票之前卖出股票，即需要在买入股票后的数组里面与其买入差值的最大值
*/

#include<iostream>

using namespace std;

int maxProfit(int* prices, int pricesSize) {
	int max = 0;
	for (int i = 0; i < pricesSize; ++i)
	{
		for (int j = i; j < pricesSize; ++j)
		{
			if (prices[j] - prices[i] > max)
			{
				max = (prices[j] - prices[i]);
			}
		}
	}
	return max;
}

int main()
{
	int prices[] = { 7,6,4,3,1 };
	int pricesSize = (sizeof(prices)) / (sizeof(prices[0]));
	int i = maxProfit(prices, pricesSize);
	cout << i;
	system("pause");
	return 0;
}