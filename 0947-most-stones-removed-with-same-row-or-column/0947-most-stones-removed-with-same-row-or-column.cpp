class Disjointset{
public:
    vector<int>rank,parent,size;
    Disjointset(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findupar(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findupar(parent[node]);
    }
    void unionbysize(int u,int v){
        int ulp_u=findupar(u);
        int ulp_v=findupar(v);
        if(ulp_u==ulp_v) return;
        if(size[ulp_v]>size[ulp_u]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }else if(size[ulp_u]>size[ulp_v]){
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }

};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int row=0;
        int col=0;
        for(auto &it :stones){
            row=max(row,it[0]);
            col=max(col,it[1]);
        }
        int offset=row+1;
        Disjointset ds(row+col+1);
        vector<int>vis(row+col+2,0);
        for(auto &it : stones){
            int fir=it[0];
            int sec=it[1]+offset;
            ds.unionbysize(fir,sec);
            vis[fir]=1;
            vis[sec]=1;
        }
        int count=0;
        for(int i=0;i<vis.size();i++){
            if(ds.parent[i]==i && vis[i]==1){
                count++;
            }
        }
        return stones.size()-count;
    }
};