class Solution {
public:
    void sear(vector<vector<char>>& grid , int r,int c){
        int ro=grid.size();
        int co=grid[0].size();
        if(r<0 || r>=ro || c<0 || c>=co || grid[r][c]=='0'){
            return;
        }
        grid[r][c]='0';
        sear(grid,r,c-1);
        sear(grid,r+1,c);
        sear(grid,r,c+1);
        sear(grid,r-1,c);
    }
    int numIslands(vector<vector<char>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        int isl=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]=='1'){
                    isl++;
                    sear(grid,i,j);
                }
            }
        }
        return isl;
    }
};