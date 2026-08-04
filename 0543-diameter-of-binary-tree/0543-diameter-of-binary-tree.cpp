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
    int diam=0;
    int dia(TreeNode* root){
        if(root==nullptr) return 0;
        int ls=dia(root->left);
        int rs=dia(root->right);
        diam=max(diam,ls+rs);
        return 1+max(ls,rs);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        dia(root);
        return diam;
    }
};