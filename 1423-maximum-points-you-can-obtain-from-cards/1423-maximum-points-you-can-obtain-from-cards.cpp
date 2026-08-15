class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int ls=0,rs=0;
        for(int i=0;i<k;i++){
            ls+=cardPoints[i];
        }
        int maxsum=ls;
        int lp=cardPoints.size()-1;
        for(int i=k-1;i>=0;i--){
            ls-=cardPoints[i];
            rs+=cardPoints[lp];
            lp--;
            maxsum=max(maxsum,ls+rs);
        }
        return maxsum;
    }
};