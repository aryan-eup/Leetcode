class Solution {
public:
    int findMin(vector<int>& nums) {
        int min=INT_MAX;
        int i=0,j=nums.size()-1;
        while(j>=i){
            int mid=i+(j-i)/2;
            if(nums[mid]>=nums[i]){
                if(nums[i]<min){
                    min=nums[i];
                }
                i=mid+1;
            }else{
                if(nums[mid]<min){
                    min=nums[mid];
                }
                j=mid-1;
            }
        }
        return min;
    }
};