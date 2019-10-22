#include<iostream>
#include<queue>
using namespace std;

//两个对列实现栈
/*queue<int> que;

void push(int x) {
	queue<int> t;
	int len = que.size();
	for (int i = 0; i < len; ++i)
	{
		int temp = que.front();
		que.pop();
		t.push(temp);
	}
	que.push(x);
	for (int i = 0; i < len; ++i)
	{
		int temp = t.front();
		t.pop();
		que.push(temp);
	}
}

int pop()
{
	if (que.empty())
		return 0;
	int i = que.front();
	que.pop();
	return i;
}

int top()
{
	if (que.empty())
		return 0;
	return que.front();
}

bool empty()
{
	return que.empty();
}*/


//先将目标值插入到对列中，再将目标值前面N-1个数据输入到对列中

queue<int>que;
void push(int x)
{
	int len = que.size();
	que.push(x);
	for (int i = 0; i < len; ++i)
	{
		int temp = que.front();
		que.pop();
		que.push(temp);
	}
}

int pop()
{
	if (que.empty())
	{
		return 0;
	}
	int i = que.front();
	que.pop();
	return i;
}

int top()
{
	if (que.empty())
	{
		return 0;
	}
	return que.front();
}

int empty()
{
	return que.empty();
}
int main()
{
	system("pause");
	return 0;
}