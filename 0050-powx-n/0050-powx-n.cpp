class Solution {
public:
    double myPow(double x, int n) {
        double ans=1;
        long long p=n;
        if(p<0){
            x=1/x;
            p=-p;
        }
        while(p>0){
            if(p%2==1){
                ans*=x;
            }
            x=x*x;
            p=p/2;
        }
        return ans;

    }
};