#include<iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
};
//������������һ���ڵ��ֵ����һ���ڵ㸳ֵ
//���ոı�ָ��
void deleteNode(ListNode* node) {
	node->val = node->next->val;
	node->next = node->next->next;
}
int main()
{
	ListNode* node;

	deleteNode(node);
	system("pause");
	return 0;
}