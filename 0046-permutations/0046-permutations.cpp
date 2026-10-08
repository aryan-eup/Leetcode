class Solution {
public:
    void sol(vector<vector<int>>&ans,vector<int>&pus,vector<int>&vis,vector<int>&nums){
        if(pus.size()==nums.size()){
            ans.push_back(pus);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!vis[i]){
                pus.push_back(nums[i]);
                vis[i]=1;
                sol(ans,pus,vis,nums);
                pus.pop_back();
                vis[i]=0;
            }
            
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>pus;
        int n=nums.size();
        vector<int>vis(n,0);
        sol(ans,pus,vis,nums);
        return ans;
    }
};