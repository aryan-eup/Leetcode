class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int sum=0;
        for(const auto& val:accounts){
            sum=max(sum,accumulate(val.begin(),val.end(),0));
        }
        return sum;
    }
};