class Solution {
public:
    vector<int>pse(vector<int>nums){
        int n=nums.size();
        vector<int>ans(n,-1);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>nums[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i]=st.top();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int>nse(vector<int>nums){
        int n=nums.size();
        vector<int>ans(n,n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i]=st.top();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int>pge(vector<int>nums){
        int n=nums.size();
        vector<int>ans(n,-1);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]<nums[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i]=st.top();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int>nge(vector<int>nums){
        int n=nums.size();
        vector<int>ans(n,n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<=nums[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i]=st.top();
            }
            st.push(i);
        }
        return ans;
    }
    long long maxsubsum(vector<int>nums){
        int n=nums.size();
        vector<int>pgei=pge(nums);
        vector<int>ngei=nge(nums);
        long long total=0;
        for(int i=0;i<n;i++){
            int rs=ngei[i]-i;
            int ls=0;
            if(pgei[i]==-1){
                ls=i+1;
            }else{
                ls=i-pgei[i];
            }
            total=(total+1ll*ls*rs*nums[i]);
        }
        return total;
    }
    long long minsubsum(vector<int>nums){
        int n=nums.size();
        vector<int>psei=pse(nums);
        vector<int>nsei=nse(nums);
        long long total=0;
        for(int i=0;i<n;i++){
            int rs=nsei[i]-i;
            int ls=0;
            if(psei[i]==-1){
                ls=i+1;
            }else{
                ls=i-psei[i];
            }
            total=(total+1ll*ls*rs*nums[i]);
        }
        return total;
    }
    long long subArrayRanges(vector<int>& nums) {
        long long n=maxsubsum(nums);
        long long m=minsubsum(nums);
        return n-m;
    }
};