#include<iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
};
bool hasCycle(ListNode *head) //回指
{
	if (head == nullptr || head->next == nullptr)
		return false;
	if (head->next == head)
		return true;
	ListNode* p = head->next;
	ListNode* c = head;
	ListNode* q = p->next;
	while (q != nullptr)
	{
		p->next = c;
		c = p;
		p = q;
		q = q->next;
	}
	if (p == head)
	{
		return true;
	}
	return false;
}


bool hasCycle(ListNode *head) //快慢指针
{
	if (head == nullptr || head->next == nullptr)
		return false;
	ListNode * slow = head->next;
	if (slow == nullptr)
		return false;
	ListNode * fast = slow->next;
	if (fast == nullptr)
		return false;
	while (fast != nullptr && slow != nullptr)
	{
		if (fast == slow)
		{
			return true;
		}
		slow = slow->next;
		fast = fast->next;
		if (fast != nullptr)
		{
			fast = fast->next;
		}
	}
	return false;
}
int main()
{

	system("pause");
	return 0;
}