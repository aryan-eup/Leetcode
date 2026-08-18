class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freq(26,0);
        for(char x:tasks){
            freq[x-'A']++;
        }
        int maxf=0;
        for(int x:freq){
            maxf=max(maxf,x);
        }
        int samef=0;
        for(int x:freq){
            if(x==maxf){
                samef++;
            }
        }
        int ans=(maxf-1)*(n+1)+samef;
        return max(ans,(int)tasks.size());
    }
};