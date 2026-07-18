class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans=0;
        for(auto c :operations){
            if(c=="++X" || c=="X++"){
                ans++;
            }else{
                ans--;
            }
        }
        return ans;
    }
};