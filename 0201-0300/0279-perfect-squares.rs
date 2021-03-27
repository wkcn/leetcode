// TODO: 其他方法
struct Solution {}

impl Solution {
    pub fn num_squares(n: i32) -> i32 {
        /*
         * dp[n] 表示数字和为n时，最少的完全平方数次数
         * 记完全平方数集合为S
         * dp[n] = min{dp[n - v], v \in S}
         */
        let mut dp = vec![i32::max_value(); n as usize + 1];
        dp[0] = 0;
        let mut s = Vec::new();
        let mut i = 1;
        while i * i <= n as i32 {  // 不会越界, 要包含sqrt(n)
            s.push(i * i);
            i += 1;
        }
        for i in 0..n as usize {
            /*
            // 不需要判断，因为dp[i]至少会被前一个数字 + 1
            if dp[i] == i32::max_value() {
                continue;
            }
            */
            for &v in s.iter() {
                if i as i32 + v > n {
                    break;
                }
                dp[i + v as usize] = dp[i + v as usize].min(dp[i] + 1);
            }
        }
        dp[n as usize]
    }
}

fn main() {
    assert_eq!(Solution::num_squares(1), 1);
    assert_eq!(Solution::num_squares(12), 3);
    assert_eq!(Solution::num_squares(13), 2);
}
