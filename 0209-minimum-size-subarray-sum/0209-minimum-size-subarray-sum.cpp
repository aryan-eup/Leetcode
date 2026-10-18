class Solution {
public:
    long long  solve(vector<int>nums,int len){
        long long curr=0,ans=0;
        for(int i=0;i<nums.size();i++){
            curr+=nums[i];
            if(i>=len) curr-=nums[i-len];
            if(i>=len-1) ans=max(ans,curr);
        }
        return ans;
    }
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=1;
        int j=nums.size();
        int ans=0;
        while(j>=i){
            int mid=i+(j-i)/2;
            long long tar=solve(nums,mid);
            if(tar>=target){
                ans=mid;
                j=mid-1;
            }else{
                i=mid+1;
            }
        }
        return ans;
    }
};