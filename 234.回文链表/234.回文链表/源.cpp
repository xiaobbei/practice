#include<iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
};


bool isPalindrome(ListNode* head) {
	if (head == nullptr || head->next == nullptr)
		return true;
	if (head->next->next == nullptr)
	{
		if (head->val == head->next->val)
			return true;
		else
			return false;
	}
	ListNode *fast = head->next->next;
	ListNode *slow = head->next;
	while (fast !=nullptr && fast->next != nullptr)
	{
		fast = fast->next->next;
		slow = slow->next;
	}

	ListNode *pcur = nullptr;
	while (head != slow)
	{
		ListNode *pnext = head->next;
		head->next = pcur;
		pcur = head;
		head = pnext;
	}
	if (fast != nullptr && fast->next == nullptr)
	{
		slow = slow->next;
	}
	while (pcur != nullptr)
	{
		if (pcur->val != slow->val)
			return false;
		pcur = pcur->next;
		slow = slow->next;
	}
	return true;
}
int main()
{
	system("pause");
	return 0;
}