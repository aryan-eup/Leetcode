class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int min=INT_MAX;
        int ans=-1;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            int left=i+1;
            int right=n-1;
            while(left<right){
                int sum=nums[i]+nums[left]+nums[right];
                int diff=abs(sum-target);
                if(diff<min){
                    min=diff;
                    ans=sum;
                }
                if(sum>target){
                    right--;
                }else{
                    left++;
                }

            }
        }
        return ans;
    }
};