class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fiv=0;
        int te=0;
        for(int x:bills){
            if(x==5){
                fiv++;
            }else if(x==10 && fiv>0){
                fiv--;
                te++;
            }else if(x==20 && fiv>0 && te>0){
                fiv--;
                te--;
            }else if(x==20 && fiv>=3){
                fiv-=3;
            }
            else{
                return false;
            }
        }
        return true;
    }
};