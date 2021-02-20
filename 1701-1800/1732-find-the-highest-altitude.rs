struct Solution {}

impl Solution {
    pub fn largest_altitude(gain: Vec<i32>) -> i32 {
        // 
        gain.iter().fold((0, 0), |acc, x| {
            let h = acc.0 + x;
            (h, acc.1.max(h))
        }).1
    }
}

fn main() {
    assert_eq!(Solution::largest_altitude(vec![-5, 1, 5, 0, -7]), 1);
}
