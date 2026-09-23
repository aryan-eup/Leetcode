class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>dis(n,vector<int>(m,1e9));
        dis[0][0]=0;
        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        >q;
        q.push({0,{0,0}});
        vector<int>rd={0,+1,0,-1};
        vector<int>cd={-1,0,+1,0};
        while(!q.empty()){
            int d=q.top().first;
            int r=q.top().second.first;
            int c=q.top().second.second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=r+rd[i];
                int ncol=c+cd[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                    int curdis=abs(heights[nrow][ncol]-heights[r][c]);
                    int newdis=max(d,curdis);
                    if(newdis<dis[nrow][ncol]){
                        dis[nrow][ncol]=newdis;
                        q.push({newdis,{nrow,ncol}});
                    }
                }
            }
        }
        return dis[n-1][m-1];
    }
};