class Solution {
public:
    vector<int> nse(vector<int>&arr){
        int n=arr.size();
        vector<int>ret(n,n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[i]<=arr[st.top()]){
                st.pop();
            }
            if(!st.empty()){
                ret[i]=st.top();
            }
            st.push(i);
        }
        return ret;
    }
    vector<int> pse(vector<int>&arr){
        int n=arr.size();
        vector<int>ret(n,-1);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[i]<arr[st.top()]){
                st.pop();
            }
            if(!st.empty()){
                ret[i]=st.top();
            }
            st.push(i);
        }
        return ret;
    }
    int sumSubarrayMins(vector<int>& arr) {
        vector<int>nsei=nse(arr);
        vector<int>psei=pse(arr);
        int mod=1e9+7;
        long long total=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            int rs=0;
            int ls=0;
            rs=nsei[i]-i;
            if(psei[i]==-1){
                ls=i+1;
            }else{
                ls=i-psei[i];
            }
            total=(total+1ll*ls*rs*arr[i])%mod;
        }
        return total;

    }
};