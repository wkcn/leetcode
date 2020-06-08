#include "common.h"
// TODO: RETRY 重新做一编，定义不同的dp[i]
#define SOLUTION 2

#if SOLUTION == 1
class Solution {
public:
    double new21Game(int N, int K, int W) {
        if (K == 0) return 1.0;
        vector<double> dp(K + W + 1); // 注意类型
        for (int i = K; i <= N && i < K + W; ++i) {
            dp[i] = 1.0;
        }
        dp[K - 1] = (double)min(N - K + 1, W) / W;
        for (int i = K - 2; i >= 0; --i) {
            dp[i] = dp[i + 1] - (dp[i + W + 1] - dp[i + 1]) / W;
        }
        return dp[0];
    }
};
#elif SOLUTION == 2

class Solution {
public:
    double new21Game(int N, int K, int W) {
        if (K == 0) return 1.0;
        // 最终数字 x \in [K, K+W-1]
        // 记录dp[i]为从分数i开始，最终得到不超过N的概率, 求dp[0]
        // 当x \in [K, K+W-1]且x < N时，即x \in [K, min(K+W-1, N)]时，dp[x] = 1
        // 当x > min(K+W-1, N)时，dp[x] = 0
        // 当0 <= x < K时，dp[x] = (dp[x+1] + dp[x+2] + ... + dp[x+W]) / W
        // dp[x-1] = (dp[x] + dp[x+1] + ... + dp[x+W-1]) / W
        // dp[K-1] =           (dp[K] + dp[K+1] + ... + dp[K+W-1]) / W
        // dp[K-2] = (dp[K-1] + dp[K] + ... + dp[K+W-2]) / W
        const int M = min(K + W - 1, N);
        queue<double> q; // len(q) == W
        double su = 0; // dp[K] + dp[K+1] + ... + dp[K+W-1]
        for (int i = K + W - 1; i >= K; --i) {
            double v = i <= M;
            q.push(v);
            su += v;
        }
        double pre = su / W; // dp[K-1]
        q.push(pre); // push dp[K-1]
        for (int i = K - 2; i >= 0; --i) {
            // compute dp[i]
            su -= q.front();
            su += pre;
            pre = su / W; q.pop();
            q.push(pre);
        }
        return pre;
    }
};

#elif SOLUTION == 3

class Solution {
public:
    double new21Game(int N, int K, int W) {
        //if (K == 0) return 1.0; // 为什么这里可以去掉条件而方法2不能去掉？？
        vector<double> dp(W + K);
        double su = 0;
        for (int i = K; i < W + K; ++i) {
            dp[i] = i <= N;
            su += dp[i];
        }
        for (int i = K-1; i >= 0; --i) {
            dp[i] = su / W;
            su = su - dp[i + W] + dp[i];
        }
        return dp[0];
    }
};

#endif

int main() {
  int N, K, W;
  cin >> N >> K >> W;
  cout << Solution().new21Game(N, K, W) << endl;
  return 0;
}
