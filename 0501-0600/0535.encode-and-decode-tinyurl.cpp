class Solution {
public:

    Solution() {
        if (chars.empty()) {
            for (int i = 0; i < 10; ++i) chars += '0' + i;
            for (int i = 0; i < 26; ++i) chars += 'a' + i;
            for (int i = 0; i < 26; ++i) chars += 'A' + i;
        }
    }

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        while (1) {
            string s;
            for (int i = 0; i < 6; ++i) {
                s += chars[rand() % chars.size()];
            }
            if (ma.count(s) == 0) {
                ma[s] = longUrl;
                return head + s;
            }
        }
        return "";
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return ma[shortUrl.substr(head.size())];
    }
private:
    static string chars;
    const string head = "http://tinyurl.com/";
    unordered_map<string, string> ma;
};

string Solution::chars;

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
