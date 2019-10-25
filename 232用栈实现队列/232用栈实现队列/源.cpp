#include<iostream>
#include<stack>
using namespace std;

stack<int> res;
stack<int> a; 
/** Push element x to the back of queue. */
void push(int x) {
	int size = res.size();
	for (int i = 0; i<size; ++i)
	{
		int t = res.top();
		res.pop();
		a.push(t);
	}
	res.push(x);
	for (int i = 0; i<size; ++i)
	{
		int t = a.top();
		a.pop();
		res.push(t);
	}
}

/** Removes the element from in front of queue and returns that element. */
int pop() {
	if (res.empty())
		return 0;
	int t = res.top();
	res.pop();
	return t;
}

/** Get the front element. */
int peek() {
	return res.top();
}

/** Returns whether the queue is empty. */
bool empty() {
	return res.empty();
}
int main()
{

	system("pause");
	return 0;
}