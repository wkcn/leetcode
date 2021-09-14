class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        using LL = long long;
        const int n = chalk.size();
        vector<LL> acc(n + 1); acc[0] = 0;
        for (int i = 0; i < n; ++i) {
            acc[i + 1] = acc[i] + chalk[i];
        }
        LL rest = k % acc.back();
        /*
          acc: [0, 5, 6, 11]
          22 % 11 = 0
         */
         auto p = upper_bound(acc.begin(), acc.end(), rest);
         return (p - acc.begin()) - 1;
    }
};
