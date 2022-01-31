class Solution {
public:
    string getHint(string secret, string guess) {
        int cnts1[10]{0}, cnts2[10]{0};
        int a = 0;
        for (int i = 0; i < secret.size(); ++i) {
            if (secret[i] == guess[i]) ++a;
            else {
                ++cnts1[secret[i] - '0'];
                ++cnts2[guess[i] - '0'];
            }
        }
        int b = 0;
        for (int i = 0; i < 10; ++i) {
             b += min(cnts1[i], cnts2[i]);
        }
        return to_string(a) + 'A' + to_string(b) + 'B';
    }
};
