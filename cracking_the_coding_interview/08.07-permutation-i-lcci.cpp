// 字典序
class Solution {
public:
    vector<string> permutation(string S) {
        const int len = S.size();
        vector<string> ans;
        ans.push_back(S);
        int kind = 1;
        for (int i = 2; i <= len; ++i) kind *= i;
        for (int k = 1; k < kind; ++k) {
            int i;
            for (i = len-2; i >= 0; --i) {
                if (S[i] < S[i+1]) break;
            }
            if (i == -1) {
                reverse(S.begin(), S.end());
            } else {
                int m = len - i - 1;
                auto p = lower_bound(S.rbegin(), S.rbegin()+m, S[i]);
                swap(S[i], *p);
                reverse(S.rbegin(), S.rbegin()+m);
            }
            ans.push_back(S);
        }
        return ans;
    }
};

// 插空
class Solution {
public:
    vector<string> permutation(string S) {
        vector<string> ans;
        ans.push_back("");
        for (char &c : S) {
            vector<string> tmp;
            for (string &s: ans) {
                const int len = s.size();
                for (int i = 0; i <= len; ++i) {
                    string t = s;
                    t.insert(i, 1, c);
                    tmp.emplace_back(t);
                }
            }
            ans = std::move(tmp);
        }
        return ans;
    }
};

// 回溯
class Solution {
public:
    vector<string> permutation(string S) {
        const int len = S.size();
        if (len == 0) return {};
        string buf;
        vector<bool> used(len, false);
        vector<string> ans;
        Inner(S, buf, used, ans);
        return ans;
    }
    void Inner(const string &S, string &buf, vector<bool> &used, vector<string> &ans) {
        if (buf.size() == S.size()) {
            ans.push_back(buf);
            return;
        }
        for (int i = 0; i < S.size(); ++i) {
            if (!used[i]) {
                used[i] = true;
                buf += S[i];
                Inner(S, buf, used, ans);
                buf.pop_back();
                used[i] = false;
            }
        }
    }
};
