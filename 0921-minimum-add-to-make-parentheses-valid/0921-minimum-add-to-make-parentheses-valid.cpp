class Solution {
public:
    int minAddToMakeValid(string s) {
        int lc=0;
        int ans=0;
        for(int x: s){
            if(x=='('){
                lc++;
            }else if(x==')' && lc>0){
                lc--;
            }else{
                ans++;
            }
        }
        ans+=lc;
        return ans;
    }
};