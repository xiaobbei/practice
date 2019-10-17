#include<iostream>
#include<stack>
using namespace std;

class MinStack {   //Ò»¸öÕ»²Ù×÷
public:
	stack<int> res;
	MinStack() {

	}

	void push(int x) {
		if (res.empty()) {
			res.push(x);
			res.push(x);
		}
		else {
			int min = res.top();
			res.push(x);
			if (min>x) {
				res.push(x);
			}
			else res.push(min);
		}
	}

	void pop() {
		res.pop();
		res.pop();
	}

	int top() {
		int temp = res.top();
		res.pop();
		int temp2 = res.top();
		res.push(temp);
		return temp2;
	}

	int getMin() {
		return res.top();
	}
};

