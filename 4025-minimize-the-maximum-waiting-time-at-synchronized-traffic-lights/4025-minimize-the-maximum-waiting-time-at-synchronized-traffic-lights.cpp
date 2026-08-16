class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        sort(lights.begin(),lights.end());
        int ans=0;
        for(int i=0;i<arrivalTime.size();i++){
            if(arrivalTime[i]%period>=lights[0] && arrivalTime[i]%period>=lights[lights.size()-1] ){
                int penalty=period-arrivalTime[i]%period;
                if(penalty>ans){
                    ans=penalty;
                }
            }
        }
        return ans;
    }
};