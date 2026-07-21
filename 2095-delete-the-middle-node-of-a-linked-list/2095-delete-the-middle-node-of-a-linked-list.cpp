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
        int len =1;
        ListNode* curr=head;
        while(curr->next!=nullptr){
            curr=curr->next;
            len++;
        }
        int mid=(len/2);
        int num=1;
        ListNode* del=head;
        while(num<mid){
            del=del->next;
            num++;
        }
        ListNode* ne=del->next;
        del->next=del->next->next;
        delete ne;
        return head;
    }
};