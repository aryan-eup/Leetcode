class Solution {
public:
    long long mod=1000000007;
    long long ways(long long k,long long m){
        long long ans=1;
        while(k>0){
            if(k%2==1){
                ans=(ans*m)%mod;
            }
            m=(m*m)%mod;
            k=k/2;
        }
        return ans;
    }
    int countGoodNumbers(long long n) {
        long long evencount=(n+1)/2;
        long long oddcount=(n)/2;
        long long evenways=ways(evencount,5);
        long long oddways=ways(oddcount,4);
        return (oddways*evenways)%mod;

    }
};