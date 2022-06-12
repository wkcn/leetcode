class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.empty()) return true;
        if (s.size() != goal.size()) return false;
        
        s += s.substr(0, s.size() - 1);
        return s.find(goal) != string::npos;
    }
};
