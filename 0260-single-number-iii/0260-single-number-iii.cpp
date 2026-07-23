class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int>ans;
        long long xr=0;
        for(auto x: nums){
            xr^=x;
        }
        long long check =xr&(-xr);
        int set=0;
        int unset=0;
        for(auto x:nums){
            if(check&x){
                set^=x;
            }else{
                unset^=x;
            }
        }
        ans.push_back(set);
        ans.push_back(unset);
        return ans;
    }
};