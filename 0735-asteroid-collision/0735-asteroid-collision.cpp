class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>st;
        for(auto x: asteroids){
            while(!st.empty() && st.back()>0 && x<0){
                if(st.back()>-x){
                    x=0;
                    break;
                }else if(st.back()==-x){
                    st.pop_back();
                    x=0;
                    break;
                }else{
                    st.pop_back();
                }
            }
            if(x!=0){
                st.push_back(x);
            }
        }
        return st;
    }
};