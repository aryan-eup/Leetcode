class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>ind(numCourses,0);
        vector<vector<int>>adj(numCourses);
        for(auto it: prerequisites){
            int fcourse=it[1];
            int scourse=it[0];
            adj[fcourse].push_back(scourse);
            ind[scourse]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(ind[i]==0){
                q.push(i);
            }
        }
        vector<int>topo;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            topo.push_back(curr);
            for(auto it :adj[curr]){
                ind[it]--;
                if(ind[it]==0) q.push(it);
            }
        }
        return topo.size()==numCourses;
    }
};