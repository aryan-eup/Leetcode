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
    TreeNode* solve(vector<int>&A,int & idx,int ub){
        if(idx==A.size() || A[idx]>ub) return nullptr;
        TreeNode* root=new TreeNode(A[idx++]);
        root->left=solve(A,idx,root->val);
        root->right=solve(A,idx,ub);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return solve(preorder ,i,INT_MAX);
    }
};