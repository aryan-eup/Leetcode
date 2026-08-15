class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0,r=0,maxf=0,maxlen=0;
        vector<int>freq(26,0);
        while(r<s.length()){
            freq[s[r]-'A']++;
            maxf=max(maxf,freq[s[r]-'A']);
            if((r-l+1)-maxf>k){
                freq[s[l]-'A']--;
                l++;
                maxf=0;
            }
            if((r-l+1)-maxf<=k){
                maxlen=max(maxlen,r-l+1);
            }
            r++;

        }
        return maxlen;
    }
};