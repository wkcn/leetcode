struct Solution {}

impl Solution {
    pub fn max_depth(s: String) -> i32 {
        let mut ans = 0;
        let mut left = 0;
        for c in s.chars() {
            match c {
                '(' => {
                    left += 1;
                    ans = ans.max(left);
                },
                ')' => {
                    left -= 1;
                }
                _ => {}
            }
        }
        ans
    }
}

fn main() {
    assert_eq!(Solution::max_depth("1 + (2 * 3)".to_string()), 1);
}
