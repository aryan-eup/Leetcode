class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto it:times){
            int curr=it[0];
            int nex=it[1];
            int time=it[2];
            adj[curr].push_back({nex,time});
        }
        vector<int>dis(n+1,1e9);
        dis[k]=0;
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        >q;
        q.push({0,k});
        while(!q.empty()){
            auto [dist,node]=q.top();
            q.pop();
            for(auto it:adj[node]){
                int nex=it.first;
                int edw=it.second;
                if(edw+dist<dis[nex]){
                    dis[nex]=edw+dist;
                    q.push({edw+dist,nex});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(dis[i]==1e9){
                return -1;
            }
            int ct=dis[i];
            ans=max(ct,ans);
        }
        return ans;
    }
};