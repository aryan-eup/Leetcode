class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>&vis,vector<vector<int>>&grid,int m,int n){
        vis[row][col]=1;
        vector<int>rd={0,+1,0,-1};
        vector<int>cd={-1,0,+1,0};
        for(int i=0;i<4;i++){
            int nrow=row+rd[i];
            int ncol=col+cd[i];
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                dfs(nrow,ncol,vis,grid,m,n);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        // end and start column
        for(int i=0;i<m;i++){
            if(grid[i][0]==1 && !vis[i][0]){
                dfs(i,0,vis,grid,m,n);
            }
            if(grid[i][n-1]==1 && !vis[i][n-1]){
                dfs(i,n-1,vis,grid,m,n);
            }
        }
        // end and start row
        for(int i=0;i<n;i++){
            if(grid[0][i]==1 && !vis[0][i]){
                dfs(0,i,vis,grid,m,n);
            }
            if(grid[m-1][i]==1 && !vis[m-1][i]){
                dfs(m-1,i,vis,grid,m,n);
            }
        }
        int count =0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    count++;
                }
            }
        }
        return count;
    }
};