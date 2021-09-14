class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        int best_i = -1;
        for (int i = 0; i < dictionary.size(); ++i) {
            if ((best_i == -1 || dictionary[i].size() > dictionary[best_i].size() ||
                 (dictionary[i].size() == dictionary[best_i].size() && dictionary[i] < dictionary[best_i])
                ) && is_valid(s, dictionary[i])) {
                best_i = i;
            }
        }
        return best_i == -1 ? "" : dictionary[best_i];
    }
    bool is_valid(string &s, string &d) {
        int i = 0, j = 0;
        while (i < s.size() && j < d.size()) {
            if (s[i] == d[j]) {
                ++i; ++j;
            } else {
                ++i;
            }
        }
        return j >= d.size();
    }
};
