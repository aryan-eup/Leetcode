class Disjoint{
    public:
    vector<int>parent;
    vector<int>size;
    Disjoint(int n){
        parent.resize(n);
        size.resize(n,1);
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
        if(size[ulp_v]>size[ulp_u]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        Disjoint ds(n);
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];
                if(mp.find(mail)==mp.end()){
                    mp[mail]=i;
                }else{
                    ds.join(mp[mail],i);
                }
            }
        }
        vector<vector<string>>mails(n);
        for(auto it:mp){
            string mail=it.first;
            int parent=ds.ulp(it.second);
            mails[parent].push_back(mail);
        }
        vector<vector<string>>ans;
        for(int i=0;i<n;i++){
            if(mails[i].size()==0) continue;
            sort(mails[i].begin(),mails[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto it: mails[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};