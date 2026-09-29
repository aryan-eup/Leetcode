class Solution {
public:

    int ulp(int node,vector<int>&parent){
        if(parent[node]==node){
            return node;
        }
        return parent[node]=ulp(parent[node],parent);
    }
    void connect(int u,int v,vector<int>&size,vector<int>&parent){
        int ulp_u=ulp(u,parent);
        int ulp_v=ulp(v,parent);
        if(ulp_u==ulp_v) return;
        if(size[ulp_u]>size[ulp_v]){
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }else{
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int ext_ed=0;
        vector<int>parent(n);
        vector<int>size(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(auto it :connections){
            int fir=it[0];
            int sec=it[1];
            if(ulp(fir,parent)==ulp(sec,parent)){
                ext_ed++;
            }else{
                connect(fir,sec,size,parent);
            }
        }
        int comp=0;
        for(int i=0;i<n;i++){
            if(parent[i]==i){
                comp++;
            }
        }
        if(comp-1<=ext_ed){
            return comp-1;
        }
        return -1;
    }
};