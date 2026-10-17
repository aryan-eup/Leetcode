class Solution {
public:
    int check(vector<int>&nums,int k,int mid){
        int count=1;
        int sum=0;
        for(auto val:nums){
            sum+=val;
            if(sum>mid){
                count++;
                sum=val;
            }
        }
        return count;
    }
    int splitArray(vector<int>& nums, int k) {
        int i=*max_element(nums.begin(),nums.end());
        int j=accumulate(nums.begin(),nums.end(),0);
        int ans =0;
        while(j>=i){
            int mid=i+(j-i)/2;
            int val=check(nums,k,mid);
            if(val<=k){
                ans=mid;
                j=mid-1;
            }else{
                i=mid+1;
            }
        }
        return ans;
    }
};