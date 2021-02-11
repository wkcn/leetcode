struct Solution {}

impl Solution {
    pub fn equal_substring(s: String, t: String, max_cost: i32) -> i32 {
        let costs: Vec<i32> = s.chars().zip(t.chars()).map(|x| i32::abs(x.0 as i32 - x.1 as i32)).collect();
        let mut left = 0;
        let mut right = 0;
        let mut ans = 0;
        let mut cur_cost = 0;
        while right < s.len() {
            cur_cost += costs[right];
            right += 1;
            while cur_cost > max_cost {
                cur_cost -= costs[left];
                left += 1;
            }
            ans = ans.max(right - left);
        }
        ans as i32
    }
}

fn main() {
    let s = "abcd".to_string();
    let t = "bcdf".to_string();
    let cost = 3;
    println!("{}", Solution::equal_substring(s, t, cost));

    let s = "abcd".to_string();
    let t = "cdef".to_string();
    let cost = 3;
    println!("{}", Solution::equal_substring(s, t, cost));

    let s = "abcd".to_string();
    let t = "acde".to_string();
    let cost = 0;
    println!("{}", Solution::equal_substring(s, t, cost));
}
