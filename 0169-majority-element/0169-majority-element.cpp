class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count =0;
        int ans=nums[0];
        for(int k:nums){
            if(k==ans){
                count++;
            }else{
                count--;
            }
            if(count==0){
                ans=k;
                count=1;
            }
        }
        return ans;
    }
};