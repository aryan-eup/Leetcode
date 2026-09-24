class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it :flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int>dis(n,1e9);
        queue<tuple<int,int,int>>q;
        q.push({src,0,0});
        dis[src]=0;
        while(!q.empty()){
            auto [node,cost,step]=q.front();
            q.pop();
            if(step>k) continue;
            for(auto it :adj[node]){
                int nex=it.first , ccost=it.second;
                if(cost+ccost<dis[nex]){
                    dis[nex]=cost+ccost;
                    q.push({nex,cost+ccost,step+1});
                }
            }
        }
        return (dis[dst]==1e9)?-1:dis[dst];
    }
};