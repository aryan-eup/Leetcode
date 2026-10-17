class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int i=0,j=arr.size()-1;
        int ans=arr.size();
        while(j>=i){
            int mid=i+(j-i)/2;
            int missing=arr[mid]-(mid +1);
            if(missing<k){
                i=mid+1;
            }else{
                ans=mid;
                j=mid-1;
            }
        }
        return ans+k;
    }
};