// DP 好题
struct Solution {}

// 正向无压缩
/*
impl Solution {
    pub fn num_distinct(s: String, t: String) -> i32 {
        let s: Vec<u8> = s.bytes().collect();
        let t: Vec<u8> = t.bytes().collect();
        let slen = s.len();
        let tlen = t.len();
        let mut dp = vec![vec![0; tlen + 1]; slen + 1];
        for i in 0..slen {
            dp[i][0] = 1;
        }
        for i in 0..slen {
            for j in 0..tlen {
                // dp[i][j + 1]指的是不保留s[i]
                dp[i + 1][j + 1] = if s[i] == t[j] {
                    dp[i][j + 1] + dp[i][j]
                } else {
                    dp[i][j + 1]
                }
            }
        }
        dp[slen][tlen]
    }
}
*/

// 正向压缩
/*
impl Solution {
    pub fn num_distinct(s: String, t: String) -> i32 {
        let s: Vec<u8> = s.bytes().collect();
        let t: Vec<u8> = t.bytes().collect();
        let slen = s.len();
        let tlen = t.len();
        let mut dp = vec![0; tlen + 1];
        dp[0] = 1;
        for i in 0..slen {
            let mut prev = 1;  // t为空字符串时
            for j in 0..tlen {
                let old = dp[j + 1];
                if s[i] == t[j] {
                    dp[j + 1] += prev;
                }
                prev = old;
            }
        }
        // 注意index是tlen
        dp[tlen]
    }
}
*/

// 逆向无压缩
/*
impl Solution {
    pub fn num_distinct(s: String, t: String) -> i32 {
        let s: Vec<u8> = s.bytes().collect();
        let t: Vec<u8> = t.bytes().collect();
        let slen = s.len();
        let tlen = t.len();
        // s[i:slen]
        let mut dp = vec![vec![0; tlen + 1]; slen + 1];
        // 包括slen
        for i in 0..=slen {
            dp[i][tlen] = 1; // t为空的情况
        }
        for i in (0..slen).rev() {
            for j in (0..tlen).rev() {
                dp[i][j] = if s[i] == t[j] {
                    dp[i+1][j] + dp[i+1][j+1]
                } else {
                    dp[i+1][j]
                }
            }
        }
        dp[0][0]
    }
}
*/
// 反向压缩
impl Solution {
    pub fn num_distinct(s: String, t: String) -> i32 {
        let s: Vec<u8> = s.bytes().collect();
        let t: Vec<u8> = t.bytes().collect();
        let slen = s.len();
        let tlen = t.len();
        // s[i:slen]
        let mut dp = vec![0; tlen + 1];
        dp[tlen] = 1;
        for i in (0..slen).rev() {
            let mut prev = 1;
            for j in (0..tlen).rev() {
                let old = dp[j];
                if s[i] == t[j] {
                    dp[j] += prev;
                }
                prev = old;
            }
        }
        dp[0]
    }
}

// TODO
// 正向非压缩，按s走
// 正向压缩，按s走
// 正向压缩逆序，不用临时变量



fn main() {
    assert_eq!(Solution::num_distinct("rabbbit".to_string(), "rabbit".to_string()), 3);
    assert_eq!(Solution::num_distinct("babgbag".to_string(), "bag".to_string()), 5);
}
