class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int color,vector<int>&row,vector<int>&col,int ini){
        image[sr][sc]=color;
        int n=image.size();
        int m=image[0].size();
        for(int i=0;i<4;i++){
            int nrow= sr+row[i];
            int ncol=sc+col[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==ini){
                dfs(image,nrow,ncol,color,row,col,ini);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<int>row={0,-1,0,+1};
        vector<int>col={-1,0,+1,0};
        int ini=image[sr][sc];
        if(ini==color) return image;
        dfs(image,sr,sc,color,row,col,ini);
        return image;

        
    }
};