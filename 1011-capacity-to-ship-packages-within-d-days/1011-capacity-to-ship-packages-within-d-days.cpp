class Solution {
public:
    int check(vector<int>&weights, int mid){
        int days=1;
        int sum=0;
        for(int i=0;i<weights.size();i++){
            sum+=weights[i];              
            if(sum>mid){
                sum=0;
                days++;
                i--;
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int i=*max_element(weights.begin(),weights.end());
        int j=accumulate(weights.begin(),weights.end(),0);
        int ans=-1;
        while(j>=i){
            int mid=i+(j-i)/2;
            int val=check(weights,mid);
            if(val<=days){
                ans=mid;
                j=mid-1;
            }else{
                i=mid+1;
            }
        }
        return ans;
    }
};