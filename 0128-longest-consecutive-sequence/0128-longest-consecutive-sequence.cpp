class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s(nums.begin(),nums.end());
        if(s.empty()) return 0;
        int ans=1;
        for(int x: s){
            if(s.find(x-1)==s.end()){
                int count=1;
                int curr=x;
                while(s.find(curr+1)!=s.end()){
                    curr++;
                    count++;
                }
                ans=max(ans,count);
            }
        }
        return ans;
    }
};