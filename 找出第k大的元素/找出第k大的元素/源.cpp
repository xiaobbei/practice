#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;

//优先级队列解决topk问题

struct cmp
{
	bool operator()(int &a, int &b)const
	{
		return a > b;
	}
};

int findMaxK(vector<int>res, int size, int k)
{
	priority_queue<int, vector<int>, cmp> myqueue;
	for (int i = 0; i < size; ++i)
	{
		if (myqueue.size() < k)
		{
			myqueue.push(res[i]);
		}
		else
		{
			int min = myqueue.top();
			if (res[i]>min)
			{
				myqueue.pop();
			}
			myqueue.push(res[i]);
		}
	}
	return myqueue.top();
}
int main()
{
	vector<int> res;
	int tmp;
	while (cin >> tmp)
	{
		res.push_back(tmp);
		if (cin.get() == '\n')
			break;
	}
	int result = findMaxK(res, res.size(), 3);
	system("pause");
	return 0;
}


/*冒泡排序，因为只需要倒数第三大，所以只需要排序三趟
int main()
{


	vector<int> input;
	int tmp;
	while (cin >> tmp)
	{
		input.push_back(tmp);
		if (cin.get() == '\n')
			break;
	}
	int n = input.size();
	for (int i = 0; i<3; i++)
	{
		for (int j = 0; j<n - i - 1; j++)
		{
			if (input[j]>input[j + 1])
			{
				tmp = input[j + 1];
				input[j + 1] = input[j];
				input[j] = tmp;
			}
		}
	}
	cout << input[n - 3];
	system("pause");
	return 0;
}*/
