class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return false;
        string addi =s+s;
        return addi.find(goal)!=string::npos;
    }
};