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
    bool isPalindrome(ListNode* head) {
        stack<int>st;
        ListNode* temp=head;
        int count=0;
        while(temp!=nullptr){
            temp=temp->next;
            count++;
        }
        int mid=(count/2)-1;
        ListNode* curr=head;
        int check=0;
        if(count%2==0){
            while(check<=mid){
                st.push(curr->val);
                curr=curr->next;
                check++;

            }
        }else{
            while(check<=mid){
                st.push(curr->val);
                curr=curr->next;
                check++;
            }
            curr=curr->next;

        }
        while(!st.empty()){
            int a=st.top();
            if(a!=curr->val){
                return false;
            }
            curr=curr->next;
            st.pop();
        }
        return true;
    }
};