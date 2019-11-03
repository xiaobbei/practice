#include<iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
};
//替身攻击，用下一个节点的值给上一个节点赋值
//最终改变指向
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