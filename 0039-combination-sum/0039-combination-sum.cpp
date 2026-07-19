class Solution {
public:
    void solve(vector<vector<int>>&ans,vector<int>&curr,vector<int>&candidates,int n,int target,int index){
        if(index==n || target<0){
            if(target==0){
                ans.push_back(curr);
            }
            return;
        }
        curr.push_back(candidates[index]);
        solve(ans,curr,candidates,n,target-candidates[index],index);
        curr.pop_back();
        solve(ans,curr,candidates,n,target,index+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>curr;
        int n=candidates.size();
        solve(ans,curr,candidates,n,target,0);
        return ans;
    }
};