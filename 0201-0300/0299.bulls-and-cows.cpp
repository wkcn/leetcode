class Solution {
public:
    string getHint(string secret, string guess) {
        /*
          公牛: 多少位属于数字且位置对
          奶牛: 数字对位置不对
         */
         int a = 0;
         array<int, 10> vis{0};
         array<int, 10> g{0};
         for (int i = 0; i < secret.size(); ++i) {
             if (secret[i] == guess[i]) ++a;
             else {
                 ++vis[secret[i] - '0'];
                 ++g[guess[i] - '0'];
             }
         }
         int b = 0;
         for (int i = 0; i < 10; ++i) {
             b += min(vis[i], g[i]);
         }
         return to_string(a) + 'A' + to_string(b) + 'B';
    }
};
