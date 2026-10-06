class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
         vector<vector<int>>ans;
         sort(nums.begin(),nums.end());
         int n=nums.size();
         for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                int left=j+1;
                int right=n-1;
                while(right>left){
                    double sum=(double)nums[i]+(double)nums[j]+(double)nums[left]+(double)nums[right];
                    if(sum==target){
                        ans.push_back({nums[i],nums[j],nums[left],nums[right]});
                        left++;
                        right--;
                    }else if(sum>target){
                        right--;
                    }else{
                        left++;
                    }
                }
            }
         }
         set<vector<int>>s(ans.begin(),ans.end());
         vector<vector<int>>fin(s.begin(),s.end());
         return fin;
    }
};