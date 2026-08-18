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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto x:lists){
            ListNode* curr=x;
            while(curr!=nullptr){
                pq.push(curr->val);
                curr=curr->next;
            }
        }
        ListNode* ans=new ListNode(0);
        ListNode* k=ans;
        while(!pq.empty()){
            k->next=new ListNode(pq.top());
            k=k->next;
            pq.pop();
        }
        return ans->next;
    }
};