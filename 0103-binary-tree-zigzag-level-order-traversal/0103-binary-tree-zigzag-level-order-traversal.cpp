/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        if(root==nullptr) return ans;
        q.push(root);
        int side=1;
        while(!q.empty()){
            int k=q.size();
            vector<int>pus;
            for(int i=0;i<k;i++){
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left!=nullptr) q.push(curr->left);
                if(curr->right!=nullptr) q.push(curr->right);
                pus.push_back(curr->val);
            }
            if(!side){
                reverse(pus.begin(),pus.end());
            }
            side=!side;
            ans.push_back(pus);
        }
        return ans;
    }
};