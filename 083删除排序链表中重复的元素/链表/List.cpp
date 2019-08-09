#include"List.h"

 NodeList *Init()
{
	NodeList* head;
	head = (NodeList *)malloc(sizeof(NodeList));
	if (head == NULL)
	{
		printf("-1");
		return head;
	}
	printf("�����ɹ�");
	head->next = NULL;
	return head;
}
 //ͷ�巨
 NodeList *Push(NodeList *N, int value)
 {
	 NodeList *P=(NodeList*)malloc(sizeof(NodeList));
	 P->value = value;
	 P->next = N;
	 return P;
 }

NodeList* deleteDuplicates(NodeList* head) {
	if (head == NULL || head->next == NULL )
	{
		return head;
	}
	NodeList *node = head;
	NodeList *cur = head->next;
	while (cur != NULL)
	{
		if (cur->value == node->value)
		{
			node->next = cur->next;
			cur = cur->next;
		}
		else
		{
			node = cur;
			cur = cur->next;
		}
	}
	return head;
}

 //���
 void NodePri(NodeList *N)
 {
	 assert(N != NULL);
	 NodeList *p;
	 p = N;
	 while (p->next!= NULL)
	 {
		 printf("%d  ", p->value);
		 p = p->next;
	 }
 }
