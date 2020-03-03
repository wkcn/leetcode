// 字典序
class Solution {
public:
    vector<string> permutation(string S) {
        sort(S.begin(), S.end());
        const int len = S.size();
        vector<string> ans;
        ans.push_back(S);
        while(1) {
            int i;
            for (i = len-2; i >= 0; --i) {
                if (S[i] < S[i+1]) break;
            }
            if (i == -1) {
                break;
            } else {
                int m = len - i - 1;
                // 注意，要使用upper_bound而不是lower_bound!!!!!!!!!!!!!!!!!
                auto p = upper_bound(S.rbegin(), S.rbegin()+m, S[i]);
                swap(S[i], *p);
                reverse(S.rbegin(), S.rbegin()+m);
            }
            ans.push_back(S);
        }
        return ans;
    }
};

// 回溯
class Solution {
public:
    vector<string> permutation(string S) {
        map<char, int> counts;
        for (char &c : S) ++counts[c];
        string buf;
        vector<string> ans;
        Inner(counts, buf, ans, S.size());
        return ans;
    }
    void Inner(map<char, int> &counts, string &buf, vector<string> &ans, int len) {
        if (buf.size() == len) {
            ans.push_back(buf);
            return;
        }
        for (auto &p : counts) {
            if (p.second > 0) {
                --p.second;
                buf += p.first;
                Inner(counts, buf, ans, len);
                buf.pop_back();
                ++p.second;
            }
        }
    }
};
