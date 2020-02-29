#include<iostream>

using namespace std;

struct ListNode { 
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(!head || !head->next || (m == n)) return head;
        ListNode *pre = head;
        ListNode *cur = head;
        ListNode *next;
        ListNode *start;
        ListNode *end;
        int count = 1;
        while(count < m){
            pre = cur;
            cur = cur -> next;
            count++;
        }
        start = pre;
        end = cur;
        pre = nullptr;
        while(count <= n){
            next = cur -> next;             //用于储存下一个结点
            cur -> next = pre;
            pre = cur;
            cur = next;
            count++;
        }
        start -> next = pre;
        end -> next = cur;
        if(m == 1) return pre;
        else return head;
    }
int main()
{
	return 0;
 } 
