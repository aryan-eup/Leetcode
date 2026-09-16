class Solution {
public:
    void dfs(int row,int col,vector<vector<char>>& grid,int n,int m){
        grid[row][col]=0;
        vector<int>rd={0,+1,0,-1};
        vector<int>cd={-1,0,+1,0};
        for(int i=0;i<4;i++){
            int nrow=row+rd[i];
            int ncol=col+cd[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1'){
                dfs(nrow,ncol,grid,n,m);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int isl=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    isl++;
                    dfs(i,j,grid,n,m);
                }
            }
        }
        return isl;
    }
};