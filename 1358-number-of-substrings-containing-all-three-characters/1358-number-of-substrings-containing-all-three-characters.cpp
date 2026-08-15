class Solution {
public:
    int numberOfSubstrings(string s) {
        int r=0,count=0;
        vector<int>ans(3,-1);
        while(r<s.size()){
            ans[s[r]-'a']=r;
            if(ans[0]!=-1 && ans[1]!=-1 && ans[2]!=-1){
                count+=1+min(ans[0],min(ans[1],ans[2]));
            }
            r++;
        }
        return count;
    }
};