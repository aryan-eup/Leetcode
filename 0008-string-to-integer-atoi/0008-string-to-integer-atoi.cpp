class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int j=s.length();
        while(i<j&&s[i]==' '){
            i++;
        }
        int sign=1;
        if(i<j &&(s[i]=='+'||s[i]=='-')){
            if(s[i]=='-'){
                sign=-1;
            }
            i++;
        }
        long long sum=0;
        while(i<j && isdigit(s[i])){
            sum=sum*10+(s[i]-'0');
            if(sum*sign>INT_MAX){
                return INT_MAX;
            }
            if(sum*sign<INT_MIN){
                return INT_MIN;
            }
            i++;
        }
        return sum*sign;
    }
};