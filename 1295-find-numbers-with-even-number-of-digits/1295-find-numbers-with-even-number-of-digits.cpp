class Solution {
public:
    int counts(int d){
        int digit=0;
        while(d>0){
            int num=d%10;
            digit++;
            d=d/10;
        }
        return digit;
    }
    int findNumbers(vector<int>& nums) {
        int count =0;
        for(int i=0;i<nums.size();i++){
            if(counts(nums[i])%2==0){
                count++;
            }
        }
        return count;
    }
};