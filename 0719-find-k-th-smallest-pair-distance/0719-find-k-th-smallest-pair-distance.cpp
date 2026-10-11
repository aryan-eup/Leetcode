class Solution {
public:
    int solve(int mid,vector<int>&nums){
        int count=0;
        int j=0;
        for(int i=0;i<nums.size();i++){
            while(j<nums.size() && nums[j]-nums[i]<=mid){
                j++;
            }
            count+=j-i-1;
        }
        return count;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int left=0;
        int n=nums.size()-1;
        int right=nums[n]-nums[0];
        while(right>left){
            int mid=left+(right-left)/2;
            int pair=solve(mid,nums);
            if(pair<k){
                left=mid+1;
            }else{
                right=mid;
            }
        }
        return left;
    }
};