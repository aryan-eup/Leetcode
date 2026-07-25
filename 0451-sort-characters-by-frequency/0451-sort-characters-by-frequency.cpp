class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        priority_queue<pair<int,char>>q;
        for(auto val:mp){
            q.push({val.second,val.first});
        }
        string ans="";
        while(!q.empty()){
            int freq=q.top().first;
            char ad=q.top().second;
            q.pop();
            while(freq--){
                ans+=ad;
            }
        }
        return ans;
    }
};