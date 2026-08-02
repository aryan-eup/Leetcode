class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1;
        int ans=nums.size();
        while(j>=i){
            int mid=i+(j-i)/2;
            if(nums[mid]>=target){
                ans=mid;
                j=mid-1;
            }else{
                i=mid+1;
            }
        }
        return i;
    }
};