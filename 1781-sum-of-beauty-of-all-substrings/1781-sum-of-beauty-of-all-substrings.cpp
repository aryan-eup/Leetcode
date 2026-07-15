class Solution {
public:
    int beautySum(string s) {
        int sum=0;
        for(int i=0 ;i<s.size();i++){
            vector<int>ans(26,0);
            for(int j=i;j<s.size();j++){
                ans[s[j]-'a']++;
                int maxi=0;
                int mini=INT_MAX;
                for(int k=0;k<26;k++){
                    if(ans[k]>0){
                        maxi=max(maxi,ans[k]);
                        mini=min(mini,ans[k]);
                    }
                }
                sum+=(maxi-mini);

            }
        }
        return sum;
    }
};