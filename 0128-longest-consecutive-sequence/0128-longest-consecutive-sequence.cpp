class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       if(nums.size()==1) return 1;
       int i=0,j=1;
       int ans=0;
       int count=1;
       while(j<nums.size()){
        if(nums[i]+1==nums[j]){
            count++;
            i++;
            j++;
        }else if(nums[i]==nums[j]){
            i++;
            j++;
        }else{
            count=1;
            i++;
            j++;
        }
        ans=max(ans,count);
       }
       return ans;

    }
};