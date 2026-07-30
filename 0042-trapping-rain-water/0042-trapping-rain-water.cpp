class Solution {
public:
    int trap(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int leftmax=0;
        int rightmax=0;
        int total=0;
        while(j>i){
            if(height[i]>=height[j]){
                if(height[j]>rightmax){
                    rightmax=height[j];
                }else{
                    total+=rightmax-height[j];
                }
                j--;
            }
            else{
                if(height[i]>leftmax){
                    leftmax=height[i];
                }else{
                    total+=leftmax-height[i];
                }
                i++;
            }
        }
        return total;
    }
};