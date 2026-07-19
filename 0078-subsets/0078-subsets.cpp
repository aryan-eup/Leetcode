class Solution {
public:
    void solve(vector<vector<int>>&ans,vector<int>&curr,vector<int>&nums,int n,int index){
        if(index==n){
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[index]);
        solve(ans,curr,nums,n,index+1);
        curr.pop_back();
        solve(ans,curr,nums,n,index+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>curr;
        int n=nums.size();
        solve(ans,curr,nums,n,0);
        return ans;
    }
};