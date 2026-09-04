class Solution {
public:
    void dfs(int node,vector<vector<int>>& isConnected ,vector<int>&vis){
        vis[node]=1;
        for(int i=0;i<isConnected.size();i++){
            if(isConnected[node][i]==1 && !vis[i]){
                dfs(i,isConnected,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v=isConnected.size();
        vector<int>vis(v,0);
        int prov=0;
        for(int i=0;i<v;i++){
            if(!vis[i]){
                prov++;
                dfs(i,isConnected,vis);
            }
        }
        return prov;
    }
};