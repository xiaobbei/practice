/*
����һ�����飬���ĵ� i ��Ԫ����һ֧������Ʊ�� i ��ļ۸�

��������ֻ�������һ�ʽ��ף������������һ֧��Ʊ�������һ���㷨�����������ܻ�ȡ���������

ע���㲻���������Ʊǰ������Ʊ��

����: [7,1,5,3,6,4]
���: 5
����: �ڵ� 2 �죨��Ʊ�۸� = 1����ʱ�����룬�ڵ� 5 �죨��Ʊ�۸� = 6����ʱ��������������� = 6-1 = 5 ��
ע���������� 7-1 = 6, ��Ϊ�����۸���Ҫ��������۸�

����˼·����Ϊ�䲻���������Ʊ֮ǰ������Ʊ������Ҫ�������Ʊ��������������������ֵ�����ֵ
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