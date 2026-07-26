/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return nullptr;
        ListNode* f=head;
        ListNode* s=head;
        ListNode* m=nullptr;
        while(f!=nullptr &&f->next!=nullptr){
            f=f->next->next;
            m=s;
            s=s->next;
        }
        m->next=s->next;
        return head;
    }
};