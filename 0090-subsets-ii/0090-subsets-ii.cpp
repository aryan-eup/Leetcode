class Solution {
public:
    void solve(vector<vector<int>>&ans,vector<int>&curr,vector<int>&nums,int n ,int index){
        ans.push_back(curr);
        if(index==n){
            return;
        }
        for(int i=index;i<nums.size();i++){
            if(i>index && nums[i-1]==nums[i]) continue;
            curr.push_back(nums[i]);
            solve(ans,curr,nums,n,i+1);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>curr;
        int n=nums.size();
        solve(ans,curr,nums,n,0);
        return ans;
    }
};