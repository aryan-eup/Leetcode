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
    ListNode* middleNode(ListNode* head) {
        if(head==nullptr) return nullptr;
        ListNode* fastptr=head;
        ListNode* slowptr=head;
        while(fastptr!=nullptr && fastptr->next!=nullptr){
            slowptr=slowptr->next;
            fastptr=fastptr->next->next;
        }
        return slowptr;
    }
};