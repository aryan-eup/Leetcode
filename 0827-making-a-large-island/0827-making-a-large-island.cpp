class Disjoint{
    public:
    vector<int>size,parent;
    Disjoint(int n){
        size.resize(n,1);
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int ulp(int node){
        if(parent[node]==node){
            return node;
        }
        return parent[node]=ulp(parent[node]);
    }
    void join(int u,int v){
        int ulp_u=ulp(u);
        int ulp_v=ulp(v);
        if(ulp_u==ulp_v) return;
        if(size[ulp_u]>size[ulp_v]){
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }else{
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
    }
};
class Solution {
public:
    bool isvalid(int row,int col,int n){
        if(col>=0 && col<n && row>=0 && row<n){
            return true;
        }
        return false;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        Disjoint ds(n*n);
        vector<int>rd={0,-1,0,+1};
        vector<int>cd={-1,0,+1,0};
        for(int i=0;i<n;i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==0) continue;
                for(int k=0;k<4;k++){
                    int nrow=i+rd[k];
                    int ncol=j+cd[k];
                    if(isvalid(nrow,ncol,n) && grid[nrow][ncol]==1){
                        ds.join(n*i+j,n*nrow+ncol);
                    }
                }
            }
        }
        int mx=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) continue;
                set<int>st;
                for(int k=0;k<4;k++){
                    int nrow=i+rd[k];
                    int ncol=j+cd[k];
                    if(isvalid(nrow,ncol,n) && grid[nrow][ncol]==1){
                        st.insert(ds.ulp(nrow*n+ncol));
                    }
                }
                int csize=1;
                for(auto it : st){
                    csize+=ds.size[it];
                }
                mx=max(mx,csize);
            }
        }
        for(int i=0;i<n*n;i++){
            mx=max(mx,ds.size[ds.ulp(i)]);
        }
        return mx;
    }
};