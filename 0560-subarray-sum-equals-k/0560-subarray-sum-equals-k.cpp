class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0]=1;
        int ans=0;
        int sum=0;
        for(int x: nums){
            sum+=x;
            int need=sum-k;
            if(mp.find(need)!=mp.end()){
                ans+=mp[need];
            }
            mp[sum]++;
        }
        return ans;
    }
};