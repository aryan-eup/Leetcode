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
    int pairSum(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* prev=nullptr;
        while(slow!=nullptr){
            ListNode* curr=slow->next;
            slow->next=prev;
            prev=slow;
            slow=curr;
        }
        int ans=INT_MIN;
        while(prev){
            ans=max(ans,prev->val+head->val);
            prev=prev->next;
            head=head->next;
        }
        return ans;
    }
};