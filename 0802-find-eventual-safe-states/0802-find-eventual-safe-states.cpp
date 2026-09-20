class Solution {
public:
    vector<int>topo(vector<vector<int>>&rev,int n){
        vector<int>ind(n,0);
        for(int i=0;i<n;i++){
            for(auto it:rev[i]){
                ind[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(ind[i]==0){
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty()){
            int t=q.front();
            q.pop();
            ans.push_back(t);
            for(auto it:rev[t]){
                ind[it]--;
                if(ind[it]==0) q.push(it);
            }
        }
        return ans;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>>rev(n);
        for(int i=0;i<n;i++){
            for(auto it:graph[i]){
                rev[it].push_back(i);
            }
        }
        vector<int>ans=topo(rev,n);
        sort(ans.begin(),ans.end());
        return ans;
    }
};