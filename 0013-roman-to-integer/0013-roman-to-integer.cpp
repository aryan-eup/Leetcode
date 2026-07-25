class Solution {
public:
    int romanToInt(string s) {
        int ans=0;
        for(char ch : s){
            if(ch=='M'){
                ans+=1000;
            }else if(ch=='D'){
                ans+=500;
            }else if(ch=='C'){
                ans+=100;
            }else if(ch=='L'){
                ans+=50;
            }else if(ch=='X'){
                ans+=10;
            }else if(ch=='V'){
                ans+=5;
            }else if(ch=='I'){
                ans+=1;
            }
        }
        int i=0;
        int j=1;
        while(j<s.size()){
            if(s[i]=='I' && s[j]=='V' || s[i]=='I' && s[j]=='X'){
                ans-=2;
            }else if(s[i]=='X' && s[j]=='L' || s[i]=='X' && s[j]=='C'){
                ans-=20;
            }else if(s[i]=='C' && s[j]=='D' || s[i]=='C' && s[j]=='M'){
                ans-=200;
            }
            i++;
            j++;
        }
        return ans;
    }
};