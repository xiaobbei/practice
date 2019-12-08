#include<iostream>
#include<stack>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
}; 

//栈实现
bool chkPalindrome(ListNode* A)
{
	// write code here
	if (A == NULL || A->next == NULL) return true;
	int len = Length_of_List(A);
	stack<int> st;
	ListNode* p = A;
	for (int i = 1; i <= len / 2; i++)
	{
		st.push(p->val);
		p = p->next;
	}
	if (len % 2 == 1) p = p->next;
	while (p != NULL)
	{
		//int k=st.top();
		if (st.top() != p->val)
			return false;
		st.pop();
		p = p->next;
	}
	return true;
}
int Length_of_List(ListNode* A)
{
	if (A == NULL) return 0;
	ListNode* p = A;
	int count = 0;
	while (p != NULL)
	{
		count++;
		p = p->next;
	}
	return count;
}


//快慢指针
bool chkPalindrome(ListNode* A) {
	// write code here
	if (A == NULL || A->next == NULL) return true;
	ListNode* slow = A;
	ListNode* fast = A;
	while (fast->next && fast->next->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	fast = slow->next;
	slow->next = NULL;
	ListNode* p;
	while (fast)
	{
		p = fast->next;
		fast->next = slow;
		slow = fast;
		fast = p;
	}
	fast = A;
	while (fast)
	{
		if (fast->val != slow->val) return false;
		fast = fast->next;
		slow = slow->next;
	}
	return true;
}