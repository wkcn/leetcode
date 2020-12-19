class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i1 = 0, i2 = 0;
        while (i1 < version1.size() || i2 < version2.size()) {
            int a1 = GetV(i1, version1);
            int a2 = GetV(i2, version2);
            if (a1 == a2) continue;
            return a1 < a2 ? -1 : 1;
        }
        return 0;
    }
    int GetV(int &i, const string &v) {
        if (i >= v.size()) return 0;
        int j = i + 1;
        while (j < v.size() && v[j] != '.') ++j;
        int t = stoi(v.substr(i, j - i));
        i = j + 1;
        return t;
    }
};
