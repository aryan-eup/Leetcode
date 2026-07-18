class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int sum=0;
        for(int i=0;i<accounts.size();i++){
            int cursum=0;
            for(int j=0;j<accounts[0].size();j++){
                cursum+=accounts[i][j];
            }
            sum=max(sum,cursum);
        }
        return sum;
    }
};