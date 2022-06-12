class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        // F(k+1) = 0 * arr[-1 - k] + 1 * arr[0 - k] + 2 * arr[1 - k] + ... + (n - 1)  * arr[n - 2 - k]
        // F(k) = 0 * arr[0 - k] + 1 * arr[1 - k] + 2 * arr[2 - k] + ... + (n - 1)  * arr[n - 1 - k]
        // F(k+1) - F(k) = arr[0 - k] + arr[1 - k] + ... + arr[n - 2 - k] - (n - 1) * arr[n - 1 - k]
        //               = sum(arr) - n * arr[n - 1 - k]
        // F(k) - F(k - 1) = sum(arr) - n * arr[n - k]
        int ans = 0;
        const int n = nums.size();
        for (int i = 1; i < n; ++i) ans += i * nums[i];
        const int su = accumulate(nums.begin(), nums.end(), 0);
        int last = ans;
        for (int k = 1; k < n; ++k) {
            last = last + su - n * nums[n - k];
            ans = max(ans, last);
        }
        return ans;
    }
};
