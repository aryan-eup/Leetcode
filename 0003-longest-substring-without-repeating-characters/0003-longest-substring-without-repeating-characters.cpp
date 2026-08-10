class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length=0;
        int i=0,j=0;
        map<char,int>mp;
        while(j<s.size()){
            if(mp.find(s[j])!=mp.end()){
                i=max(mp[s[j]]+1,i);
            }
            mp[s[j]]=j;
            length=max(length,j-i+1);
            j++;
        }
        return length;
    }
};