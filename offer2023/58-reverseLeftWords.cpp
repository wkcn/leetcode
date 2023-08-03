class Solution {
public:
    string reverseLeftWords(string s, int n) {
        string t(s.size(), ' ');
        for (int i = 0; i < s.size(); ++i) {
            t[i] = s[(i + n) % s.size()];
        }
        return t;
    }
};

class Solution {
public:
    void rev(string &s, int i, int j) {
        // [i, j]
        while (i < j) {
            swap(s[i++], s[j--]);
        }
    }
    string reverseLeftWords(string s, int n) {
        // AB -> BA
        // (AB)^T -> B^T A^T
        // -> BA
        rev(s, 0, n - 1);
        rev(s, n, s.size() - 1);
        rev(s, 0, s.size() - 1);
        return s;
    }
};

class Solution {
public:
    void rev(string &s, int i, int j) {
        // [i, j]
        while (i < j) {
            swap(s[i++], s[j--]);
        }
    }
    string reverseLeftWords(string s, int n) {
        // AB -> BA
        // (AB)^T -> B^T A^T
        // -> BA
        rev(s, 0, s.size() - 1);
        rev(s, 0, s.size() - n - 1);
        rev(s, s.size() - n, s.size() - 1);
        return s;
    }
};
