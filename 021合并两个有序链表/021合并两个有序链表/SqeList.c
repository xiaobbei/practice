#include<stdio.h>
#include<stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	if (l1 == NULL)
	{
		return l2;
	}
	if (l2 == NULL)
	{
		return l1;
	}
	struct ListNode *rhead = (struct ListNode *)malloc(sizeof(struct ListNode));
	struct ListNode *cur = rhead;
	while (l1 != NULL&&l2 != NULL)
	{
		if (l1->val <= l2->val)
		{
			cur->next = l1;
			cur = cur->next;
			l1 = l1->next;
		}
		else
		{
			cur->next = l2;
			cur = cur->next;
			l2 = l2->next;
		}
	}

	if (l1)
	{
		cur->next = l1;
	}
	else
	{
		cur->next = l2;
	}
	return rhead;
}