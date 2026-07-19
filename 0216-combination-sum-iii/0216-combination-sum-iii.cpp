class Solution {
public:
    void solve(vector<vector<int>>&ans,vector<int>&curr,int k,int n,int index){
        if(curr.size()==k){
            if(n==0){
                ans.push_back(curr);
            }
            return;
        }
        for(int i=index;i<10;i++){
            if(i>n) break;
            curr.push_back(i);
            solve(ans,curr,k,n-i,i+1);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>curr;
        solve(ans,curr,k,n,1);
        return ans;
    }
};