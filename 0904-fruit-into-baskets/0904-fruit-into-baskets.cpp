class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int,int>mp;
        int i=0;
        int len=0;
        for(int j=0;j<fruits.size();j++){
            mp[fruits[j]]++;
            while(mp.size()>2){
                mp[fruits[i]]--;
                if(mp[fruits[i]]==0){
                    mp.erase(fruits[i]);
                }
                i++;
            }
            len=max(len,j-i+1);
        }
        return len;
    }
};