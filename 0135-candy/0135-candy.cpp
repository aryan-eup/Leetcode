class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        if(n<1) return 0;
        int ans=1;
        int i=1;
        while(i<n){
            if(ratings[i]==ratings[i-1]){
                ans+=1;
                i++;
                continue;
            }
            int peak=1;
            while(i<n && ratings[i]>ratings[i-1]){
                peak++;
                ans+=peak;
                i++;
            }
            int down=1;
            while(i<n && ratings[i]<ratings[i-1]){
                ans+=down;
                i++;
                down++;
            }
            if(down>peak){
                ans+=down-peak;
            }
        }
        return ans;
    }
};