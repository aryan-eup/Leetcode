class Solution {
public:
    int maxDepth(string s) {
        int maxcount=0;
        int count=0;
        for(auto val:s){
            if(val=='('){
                count++;
            }else if(val==')'){
                count--;
            }
            maxcount=max(count,maxcount);
        }
        return maxcount;
    }
};