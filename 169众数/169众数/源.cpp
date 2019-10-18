#include<iostream>
#include<vector>
#include<map>
#include<stack>
#include<set>
using namespace std;

/*可以用摩尔投票法（推荐高效低内存）。它设置一个临时变量x,初始值是 x=data[0]。
还有一个计数变量count。然后i从1len的遍历数组data[]，遇到与x相同的数那就count++，
与x不同那就count--。当count==0时就x=data[i]。遍历结束后的x取值就是众数。*/
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


//暴力法求解
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


//相同栈，相同入栈，不同出栈，返回栈顶
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

//排序法：排完序中间元素为众数



int main()
{
	system("pause");
	return 0;
}