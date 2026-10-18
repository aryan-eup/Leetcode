class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        long long csum=0;
        int ans=INT_MAX;
        int left=0;
        for(int right=0;right<nums.size();right++){
            csum+=nums[right];
            while(csum>=target){
                ans=min(ans,right-left+1);
                csum-=nums[left++];
            }
        }
        return ans==INT_MAX?0:ans;
    }
};