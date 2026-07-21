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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==nullptr || head->next==nullptr) return nullptr;
        int count=1;
        ListNode* curr=head;
        while(curr->next!=nullptr){
            curr=curr->next;
            count++;
        }
        if(count==n) return head->next;
        int del=count-n;
        int len=1;
        ListNode* check=head;
        while(len!=del){
            check=check->next;
            len++;
        }
        ListNode* temp=check->next;
        check->next=check->next->next;
        delete temp;
        return head;
    }
};