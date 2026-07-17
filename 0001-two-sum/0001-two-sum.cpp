class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>m;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            int k=target-nums[i];
            if(m.contains(k)){
                ans.push_back(m[k]);
                ans.push_back(i);
            }
            m[nums[i]]=i;
        }
        return ans;
    }
};