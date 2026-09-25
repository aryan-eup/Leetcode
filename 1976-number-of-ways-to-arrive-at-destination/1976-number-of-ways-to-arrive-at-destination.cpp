class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it :roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<long long>dis(n,1e18);
        dis[0]=0;
        vector<int>way(n,0);
        way[0]=1;
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long ,int>>>q;
        q.push({0,0});
        int mod=1e9+7;
        while(!q.empty()){
            auto [dist,node]=q.top();
            q.pop();
            for(auto it:adj[node]){
                int nex=it.first;
                long long edw=it.second;
                if(edw+dist<dis[nex]){
                    dis[nex]=edw+dist;
                    way[nex]=way[node];
                    q.push({edw+dist,nex});
                }else if(edw+dist==dis[nex]){
                    way[nex]=(way[nex]+way[node])%mod;
                }
            }
        }
        return way[n-1]%mod;
    }
};