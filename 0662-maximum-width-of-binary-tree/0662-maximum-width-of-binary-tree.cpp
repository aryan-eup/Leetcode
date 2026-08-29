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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==nullptr) return 0;
        int ans=INT_MIN;
        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        while(!q.empty()){
            int k=q.size();
            long long sub=q.front().second;
            int left,right;
            for(int i=0;i<k;i++){
                long long idx=q.front().second-sub;
                TreeNode* curr=q.front().first;
                q.pop();
                if(i==0) left=idx;
                if(i==k-1) right=idx;
                if(curr->left!=nullptr) q.push({curr->left,2*idx+1});
                if(curr->right!=nullptr) q.push({curr->right,2*idx+2});
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};