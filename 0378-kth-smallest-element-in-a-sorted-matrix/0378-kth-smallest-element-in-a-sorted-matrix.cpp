class Solution {
public:
    int check(int mid,vector<vector<int>>&matrix){
        int row=0;
        int col=matrix[0].size()-1;
        int count=0;
        while(col>=0 && row<matrix.size()){
            if(mid<matrix[row][col]){
                col--;
            }else if(mid>=matrix[row][col]){
                count+=col+1;
                row++;
            }
        }
        return count;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int low=matrix[0][0];
        int high=matrix[matrix.size()-1][matrix[0].size()-1];
        while(high>low){
            int mid=low+(high-low)/2;
            int count=check(mid,matrix);
            if(count<k){
                low=mid+1;
            }else{
                high=mid;
            }
        }
        return high;
    }
};