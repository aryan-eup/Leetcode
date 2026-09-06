class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>>q;
        int n=grid.size();
        int m=grid[0].size();
        int vis[n][m];
        int forn=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }else{
                    vis[i][j]=0;
                }
                if(grid[i][j]==1){
                    forn++;
                }
            }
        }
        int rd[]={-1,0,+1,0};
        int cd[]={0,+1,0,-1};
        int cnt=0;
        int mxt=0;
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            q.pop();
            mxt=max(mxt,t);
            for(int i=0;i<4;i++){
                int row=r+rd[i];
                int col=c+cd[i];
                if(row>=0 && row<n && col>=0 && col<m && vis[row][col]!=2 && grid[row][col]==1){
                    q.push({{row,col},t+1});
                    cnt++;
                    vis[row][col]=2;
                }
            }
        }
        if(cnt!=forn) return -1;
        return mxt;
    }
};