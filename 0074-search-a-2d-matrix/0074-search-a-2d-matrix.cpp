class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int first_row=0;
        int last_row=matrix.size()-1;
        int first_col=0;
        int last_col=matrix[0].size()-1;
        while(last_row>=first_row){
            int mid=first_row+(last_row-first_row)/2;
            if(target>=matrix[mid][0] && target<=matrix[mid][last_col]){
                int left=0;
                int right=matrix[0].size()-1;
                while(right>=left){
                    int mid2=left+(right-left)/2;
                    if(matrix[mid][mid2]==target){
                        return true;
                    }else if(matrix[mid][mid2]>target){
                        right=mid2-1;
                    }else{
                        left=mid2+1;
                    }
                }
                return false;
            }else if(target>matrix[mid][0]){
                first_row=mid+1;
            }else{
                last_row=mid-1;
            }
        }
        return false;
    }
};