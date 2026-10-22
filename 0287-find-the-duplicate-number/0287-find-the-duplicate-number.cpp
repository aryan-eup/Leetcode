class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i=0;
        int j=nums.size()-1;
        int ans=-1;
        while(j>=i){
            int mid=i+(j-i)/2;
            int count=0;
            for(int x:nums){
                if(x<=mid){
                    count++;
                }
            }
            if(count>mid){
                j=mid-1;
                ans=mid;
            }else{
                i=mid+1;
            }
        }
        return ans;
    }
};