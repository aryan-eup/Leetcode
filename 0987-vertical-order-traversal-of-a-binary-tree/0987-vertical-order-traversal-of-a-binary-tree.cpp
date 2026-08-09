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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>mp;
        vector<vector<int>>ans;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            int col=temp.second.first;
            int row=temp.second.second;
            TreeNode* curr=temp.first;
            mp[col][row].insert(curr->val);
            if(curr->left!=nullptr) q.push({curr->left,{col-1,row+1}});
            if(curr->right!=nullptr) q.push({curr->right,{col+1,row+1}});
        }
        for(auto x: mp){
            vector<int>pus;
            for(auto y:x.second){
                for(auto k:y.second){
                    pus.push_back(k);
                }
            }
            ans.push_back(pus);
        }
        return ans;

    }
};