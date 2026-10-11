class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int fcol=0;
        int lcol=mat[0].size();
        while(lcol>=fcol){
            int mid=fcol+(lcol-fcol)/2;
            int row=0;
            int val=0;
            for(int i=0;i<mat.size();i++){
                if(mat[i][mid]>val){
                    val=mat[i][mid];
                    row=i;
                }
            }
            int left=(mid>0)?mat[row][mid-1]:-1;
            int right=(mid<mat[0].size()-1)?mat[row][mid+1]:-1;
            if(mat[row][mid]>left && mat[row][mid]>right){
                return {row,mid};
            }else if(right >mat[row][mid]){
                fcol=mid+1;
            }else{
                lcol=mid-1;
            }
        }
        return {-1,-1};
    }
};