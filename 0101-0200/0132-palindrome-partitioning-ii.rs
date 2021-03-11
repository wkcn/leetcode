// 回文串，好题！
struct Solution {}

impl Solution {
    pub fn min_cut(s: String) -> i32 {
        let s: Vec<_> = s.bytes().collect();
        let n = s.len();
        let mut ps = vec![vec![true; n]; n];
        for i in (0..n - 1).rev() {
            for j in i+1..n {
                ps[i][j] = s[i] == s[j] && ps[i + 1][j - 1];
            }
        }
        let mut dp = vec![i32::max_value(); n];
        for i in 0..n {
            if ps[0][i] {
                // 如果本来s[..i]就是回文字
                dp[i] = 0;
            } else {
                for j in 0..i {
                    if ps[j + 1][i] {
                        dp[i] = dp[i].min(dp[j] + 1);
                    }
                }
            }
                
        }
        dp[n - 1]
    }
}

fn main() {
    assert_eq!(Solution::min_cut("aab".to_string()), 1);
    assert_eq!(Solution::min_cut("a".to_string()), 0);
    assert_eq!(Solution::min_cut("ab".to_string()), 1);
}
