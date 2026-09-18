class Solution {
public:
    bool dfs(vector<int>&vis,vector<vector<int>>&graph,int curr,bool dir){
        if(dir){
            vis[curr]=1;
        }else{
            vis[curr]=0;
        }
        for(int adj : graph[curr]){
            if(vis[adj]==-1){
                if(!dfs(vis,graph,adj,!dir)){
                    return false;
                }
            }
            else if(vis[adj]==dir){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>vis(n,-1);
        bool dir=true;
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                if(!dfs(vis,graph,i,dir)){
                    return false;
                }
            }
        }
        return true;
    }
};