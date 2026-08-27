class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i=0;
        int maxidx=0;
        while(i<nums.size()){
            if(i>maxidx){
                return false;
            }
            maxidx=max(maxidx,i+nums[i]);
            i++;
        }
        return true;
    }
};