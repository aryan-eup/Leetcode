class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();

    
        int i = 0, j = n - 1;
        while (i <= j) {
            int mid = i + (j - i) / 2;
            if (nums[mid] >= target)
                j = mid - 1;
            else
                i = mid + 1;
        }

        int first = i;

        
        if (first == n || nums[first] != target)
            return {-1, -1};

       
        i = 0;
        j = n - 1;
        while (i <= j) {
            int mid = i + (j - i) / 2;
            if (nums[mid] > target)
                j = mid - 1;
            else
                i = mid + 1;
        }

        int last = i - 1;

        return {first, last};
    }
};