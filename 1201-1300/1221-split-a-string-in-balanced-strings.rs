struct Solution {}

impl Solution {
    pub fn balanced_string_split(s: String) -> i32 {
        let mut cnt = 0;
        let mut ans = 0;
        for c in s.bytes() {
            if c == b'L' {
                cnt += 1;
            } else {
                cnt -= 1;
            }
            if cnt == 0 {
                ans += 1;
            }
        }
        ans
    }
}

fn main() {
    assert_eq!(Solution::balanced_string_split("RLRRLLRLRL".to_string()), 4);
}
