const string S[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> se;
        for (const string &s : words) {
            string buf;
            for (char c : s) {
                buf += S[c - 'a'];
            }
            se.insert(buf);
        }
        return se.size();
    }
};
