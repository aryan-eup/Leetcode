class Solution {
public:
    void dfs(int row,int col,vector<vector<char>>&board,vector<vector<int>>&vis,int m,int n){
        vis[row][col]=1;
        vector<int>rd={0,+1,0,-1};
        vector<int>cd={-1,0,+1,0};
        for(int i=0;i<4;i++){
            int nrow=row+rd[i];
            int ncol=col+cd[i];
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !vis[nrow][ncol] && board[nrow][ncol]=='O'){
                dfs(nrow,ncol,board,vis,m,n);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        // end row and starting row
        for(int i=0;i<n;i++){
            if(board[0][i]=='O' && !vis[0][i]){
                dfs(0,i,board,vis,m,n);
            }
            if(board[m-1][i]=='O' && !vis[m-1][i]){
                dfs(m-1,i,board,vis,m,n);
            }
        }
        // end col and starting col
        for(int i=0;i<m;i++){
            if(board[i][0]=='O' && !vis[i][0]){
                dfs(i,0,board,vis,m,n);
            }
            if(board[i][n-1]=='O' && !vis[i][n-1]){
                dfs(i,n-1,board,vis,m,n);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};