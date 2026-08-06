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
    int ans=INT_MIN;
    int solve(TreeNode* node){
        if(node==NULL) return 0;
        int lh=max(0,solve(node->left));
        int rh=max(0,solve(node->right));
        ans=max(ans,(lh+rh+node->val));
        return node->val+max(lh,rh);
    }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return ans;
    }
};