class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()) return false;
        unordered_map<char,char>so;
        unordered_map<char,char>sw;
        for(int i=0;i<s.size();i++){
            if(so.count(s[i]) && so[s[i]]!=t[i]){
                return false;
            }
            if(sw.count(t[i]) && sw[t[i]]!=s[i]){
                return false;
            }
            so[s[i]]=t[i];
            sw[t[i]]=s[i];
        }
        return true;
    }
};