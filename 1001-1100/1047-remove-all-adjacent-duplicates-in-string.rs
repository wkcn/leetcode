struct Solution {}

impl Solution {
    pub fn remove_duplicates(s: String) -> String {
        let mut ans = String::new();
        for c in s.chars() {
            if !ans.is_empty() && ans.chars().last().unwrap() == c {
                ans.pop();
            } else {
                ans += &c.to_string();
            }
        }
        ans
    }
}

fn main() {
    assert_eq!(Solution::remove_duplicates("abbaca".to_string()), "ca".to_string());
}
