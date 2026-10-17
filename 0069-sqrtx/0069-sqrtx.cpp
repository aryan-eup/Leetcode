class Solution {
public:
    int mySqrt(int x) {
        if(x==0){
            return 0;
        }
        int i=1;
        int j=x/2;
        int ans=1;
        while(j>=i){
            int mid=i+(j-i)/2;
            if(mid<=x/mid){
                ans=mid;
                i=mid+1;
            }else{
                j=mid-1;
            }
        }
        return ans;
    }
};