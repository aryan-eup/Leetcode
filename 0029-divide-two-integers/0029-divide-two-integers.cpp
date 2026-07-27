class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor) return 1;
        int sign=1;
        if(dividend >0 && divisor <0) sign=0;
        if(dividend <0 && divisor>0) sign=0;
        long n=abs(long(dividend));
        long r=abs(long(divisor));
        long ans=0;
        while(n>=r){
            int count=0;
            while(n>=r*(1l<<(count+1))){
                count++;
            }
            ans+=1l<<count;
            n-=r*(1l<<count);
        }
        if(ans>INT_MAX && sign==1){
            return INT_MAX;
        }
        if(ans>INT_MAX && sign==0){
            return INT_MIN;
        } 
        return sign==1?ans:(-1)*ans;
    }
};