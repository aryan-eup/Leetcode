class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                }
            }
        }
        vector<vector<int>>ans(n,vector<int>(m,0));
        vector<int>rd={0,+1,0,-1};
        vector<int>cd={-1,0,+1,0};
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int dis=q.front().second;
            q.pop();
            ans[row][col]=dis;
            for(int i=0;i<4;i++){
                int crow=row+rd[i];
                int ccol=col+cd[i];
                if(crow>=0 && crow<n && ccol>=0 && ccol<m && mat[crow][ccol]==1){
                    mat[crow][ccol]=0;
                    q.push({{crow,ccol},dis+1});
                }
            }
        }
        return ans;
    }
};