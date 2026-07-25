class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int count=0;
        for(auto c:s){
            if(c=='(' && count++ >0) ans+='(';
            if(c==')' && count-- >1) ans+=')';
        }
        return ans;
    }
};