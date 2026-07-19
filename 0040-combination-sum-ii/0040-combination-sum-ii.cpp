class Solution {
public:
    void solve(vector<vector<int>>&ans,vector<int>&curr,vector<int>&candidates,int n,int target,int index){
        if(target==0){
            ans.push_back(curr);
            return;
        }
        if(index==n){
            return;
        }
        for(int i=index;i<candidates.size();i++){
            if(i>index && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) break;
            curr.push_back(candidates[i]);
            solve(ans,curr,candidates,n,target-candidates[i],i+1);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>curr;
        int n=candidates.size();
        solve(ans,curr,candidates,n,target,0);
        return ans;
    }
};