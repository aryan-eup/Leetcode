class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int ans=0;
        for(string &s:sentences){
            int blank=0;
            for(char c : s){
                if(c==' '){
                    blank++;
                }
            }
            ans=max(ans,blank+1);

        }
        return ans;
        
    }
};