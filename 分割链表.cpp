#include<iostream>

using namespace std;

 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* partition(ListNode* head, int x) {
       
        if(head==NULL){
            return NULL;
        }
        //�ֱ�������ͷ�ڵ㣬С��x�ķ���һ��������ķ�����һ��
        ListNode* dummy1 = new ListNode(0);
        ListNode* dummy2 = new ListNode(0);
        ListNode* p = dummy1;
        ListNode* q = dummy2;
        ListNode* cur = head;
        while(cur!=NULL){
            if(cur->val < x){
                p->next = cur;
                cur = cur->next;
                p = p->next;
                p->next = NULL;//�ָ���
            }
            else{
                q->next = cur;
                cur = cur->next;
                q = q->next;
                q->next = NULL;
            }

        }
        p->next = dummy2->next;//dummy1��β�����ӵ�dummy2��ͷ��
        return dummy1->next;

    }
    
int main()
{
	return 0;
 } 
