use std::collections::HashSet;

struct Solution {}

impl Solution {
    pub fn find_repeat_number(nums: Vec<i32>) -> i32 {
        let mut ma = HashSet::new();
        for x in nums.into_iter() {
            if ma.contains(&x) {
                return x;
            }
            ma.insert(x);
        }
        -1
    }
}

fn main() {
    let v = vec![2, 3, 1, 0, 2, 5, 3];
    println!("{}", Solution::find_repeat_number(v));
}
