class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1;
        int ans =-1;
        while(j>=i){
            int mid=i + (j-i)/2;
            if(nums[mid]>target){
                j=mid-1;
            }else if(nums[mid]<target){
                i=mid+1;
            }else{
                ans=mid;
                break;
            }
        }
        return ans;
    }
};