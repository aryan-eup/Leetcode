class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi=0;
        int min=prices[0];
        for(int i=1;i<prices.size();i++){
            if(prices[i]<min){
                min=prices[i];
            }else{
                int idx=0;
                idx=prices[i];
                maxi=max(maxi,idx-min);
            }
        }
        return maxi;
    }
};