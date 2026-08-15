class Solution {
public:
    int fxn(vector<int>&nums,int goal){
        if(goal<0) return 0;
        int r=0,l=0,cnt=0,sum=0;
        while(r<nums.size()){
            sum+=nums[r];
            while(sum>goal){
                sum-=nums[l];
                l++;
            }
            cnt+=r-l+1;
            r++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return fxn(nums,goal)-fxn(nums,goal-1);
    }
};