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
    TreeNode* soln(vector<int>&postorder,int pstrt,int pend,vector<int>&inorder,int istrt,int iend,map<int,int>&mp ){
        if(pstrt>pend || istrt>iend) return nullptr;
        int idx=mp[postorder[pend]];
        int rem=idx-istrt;
        TreeNode* root=new TreeNode(postorder[pend]);
        root->left=soln(postorder,pstrt,pstrt+rem-1,inorder,istrt,idx-1,mp);
        root->right=soln(postorder,pstrt+rem,pend-1,inorder,idx+1,iend,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        TreeNode* root=soln(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,mp);
        return root;
    }
};