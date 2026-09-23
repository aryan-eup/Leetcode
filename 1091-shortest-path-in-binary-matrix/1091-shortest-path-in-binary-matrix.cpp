class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        q.push({0,0});
        if(grid[0][0]==1 || grid[n-1][m-1]==1){
            return -1;
        }
        grid[0][0]=1;
        vector<int>rd={0,-1,-1,-1,0,+1,+1,+1};
        vector<int>cd={-1,-1,0,+1,+1,+1,0,-1};
        int dis=1;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int r=q.front().first;
                int c=q.front().second;
                if(r==n-1 && c==m-1){
                    return dis;
                }
                q.pop();
                for(int i=0;i<8;i++){
                    int nrow=r+rd[i];
                    int ncol=c+cd[i];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==0){
                        grid[nrow][ncol]=1;
                        q.push({nrow,ncol});
                    }
                }
            }
            dis++;
        }
        return -1;
    }
};