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
    ListNode* sortList(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev=nullptr;
        while(fast!=nullptr && fast->next!=nullptr){
            prev=slow;
            fast=fast->next->next;
            slow=slow->next;

        }
        prev->next=nullptr;
        ListNode* l1=sortList(head);
        ListNode* l2=sortList(slow);
        return mergelist(l1,l2);
    }
    ListNode* mergelist(ListNode* l1,ListNode* l2){
        ListNode* curr=new ListNode(0);
        ListNode* soln=curr;
        while(l1!=nullptr && l2!=nullptr){
            if(l1->val>=l2->val){
                soln->next=l2;
                l2=l2->next;
            }else{
                soln->next=l1;
                l1=l1->next;
            }
            soln=soln->next;
        }
        if(l1!=nullptr){
            soln->next=l1;
        }
        if(l2!=nullptr){
            soln->next=l2;
        }
        return curr->next;
    }
};