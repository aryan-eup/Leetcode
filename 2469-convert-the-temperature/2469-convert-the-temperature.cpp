class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        double k=celsius+273.15;
        double f=(celsius*9.00/5.00) +32.00;
        vector<double>ans;
        ans.push_back(k);
        ans.push_back(f);
        return ans;
    }
};