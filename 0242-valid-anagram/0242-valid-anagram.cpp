class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        unordered_map<char,int>mp;
        for(auto c:s){
            mp[c]++;
        }
        for(auto c:t){
            mp[c]--;
        }
        for(auto x: mp){
            if(x.second!=0){
                return false;
            }
        }
        return true;
    }
};