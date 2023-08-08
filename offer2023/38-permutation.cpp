class Solution {
public:
    vector<string> permutation(string s) {
        sort(s.begin(), s.end());
        vector<string> ans;
        ans.push_back(s);
        // 1239457 -> 1239475
        while (1) {
            int i = s.size() - 1;
            while (i > 0 && s[i-1] >= s[i]) --i;
            if (i == 0) break;
            // 将s[i-1]插入到后面的逆序序列中
            auto p = upper_bound(s.rbegin(), s.rbegin() + (s.size() - i), s[i - 1]);
            swap(*p, s[i - 1]);
            reverse(s.begin() + i, s.end());
            ans.push_back(s);
        }
        return ans;
    }
};

class Solution {
public:
    vector<string> permutation(string s) {
        vector<string> ans;
        string buf(s.size(), ' ');
        vector<bool> vis(s.size(), false);
        const int n = s.size();
        sort(s.begin(), s.end());
        function<void(int)> F = [&](int i) {
            if (i == n) {
                ans.push_back(buf);
                return;
            }
            for (int j = 0; j < n; ++j) {
                if (!vis[j] && (j == 0 || (s[j - 1] != s[j] || vis[j - 1]))) {
                    buf[i] = s[j];
                    vis[j] = true;
                    F(i + 1);
                    vis[j] = false;
                }
            }
        };
        F(0);
        return ans;
    }
};
