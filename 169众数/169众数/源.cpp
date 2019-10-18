#include<iostream>
#include<vector>
#include<map>
#include<stack>
#include<set>
using namespace std;

/*������Ħ��ͶƱ�����Ƽ���Ч���ڴ棩��������һ����ʱ����x,��ʼֵ�� x=data[0]��
����һ����������count��Ȼ��i��1len�ı�������data[]��������x��ͬ�����Ǿ�count++��
��x��ͬ�Ǿ�count--����count==0ʱ��x=data[i]�������������xȡֵ����������*/
int majorityElement(vector<int>& nums) {
	int x = nums[0];
	int count = 0;
	for (auto e : nums)
	{
		if (count == 0)
			x = e;
		if (e == x)
			count++;
		else
			count--;
	}
	return x;
}	


//���������
int majorityElement_2(vector<int>& nums) {
	int half_len = nums.size() / 2;
	int max_count = 0;
	map<int, int>count;
	for (auto it : nums)
	{
		count[it]++;
		if (count[it] > max_count)
		{
			max_count = count[it];
			if (max_count > half_len)
			{
				return it;
			}
		}
	}
}


//��ͬջ����ͬ��ջ����ͬ��ջ������ջ��
int majorityElement_3(vector<int>& nums) {
	stack<int> res;
	for (auto it : nums)
	{
		if (res.empty() == 0)
			res.push(it);
		if (res.empty() != 0 && res.top() != it)
			res.pop();
		else if (res.empty() != 0 && res.top() == it)
			res.push(it);
	}
	return res.top();
}

//���򷨣��������м�Ԫ��Ϊ����



int main()
{
	system("pause");
	return 0;
}