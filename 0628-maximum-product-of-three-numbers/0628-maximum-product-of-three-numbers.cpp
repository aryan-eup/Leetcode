class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        vector<int>neg;
        vector<int>pos;
        for(auto &x:nums){
            x<0?neg.push_back(x):pos.push_back(x);
        }
        if(neg.size()>1){
            sort(neg.begin(),neg.end(),greater<int>());
        }
        if(pos.size()>1){
            sort(pos.begin(),pos.end());
        }
        int ng=neg.size();
        int np=pos.size();
        if(ng==0 || ng==1){
            return pos[np-1]*pos[np-2]*pos[np-3];
        }
        if(pos.size()==0){
            return neg[0]*neg[1]*neg[2];
        }
        if(neg.size()>=2){
            if(pos.size()==1){
                return neg[ng-1]*neg[ng-2]*pos[np-1];
            }else{
                if(neg[ng-1]*neg[ng-2]>pos[np-1]*pos[np-2]){
                    return neg[ng-1]*neg[ng-2]*pos[np-1];
                }
                if(pos.size()>2){
                    if(neg[ng-1]*neg[ng-2]*pos[np-1]>pos[np-1]*pos[np-2]*pos[np-3]){
                        return neg[ng-1]*neg[ng-2]*pos[np-1];
                    }
                }
            }
        }
        if(pos.size()==2){
            return neg[ng-1]*neg[ng-2]*pos[np-1];
        }
        return pos[np-1]*pos[np-2]*pos[np-3];
    }
};