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
    bool solve(TreeNode* root,long long max_val,long long min_val){
        if(root==nullptr) return true;
        if(root->val >=max_val || root->val<=min_val){
            return false;
        }
        return solve(root->left,root->val,min_val)&&solve(root->right,max_val,root->val);
    }
    bool isValidBST(TreeNode* root) {
        return solve(root,LLONG_MAX,LLONG_MIN);
    }
};