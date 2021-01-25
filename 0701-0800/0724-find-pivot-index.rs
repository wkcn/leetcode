struct Solution {}

impl Solution {
    pub fn pivot_index(nums: Vec<i32>) -> i32 {
        let su = nums.iter().fold(0, |acc, x| acc + x);
        let mut acc = 0;
        for i in 0..nums.len() {
            if acc == su - acc - nums[i] {
                return i as i32;
            }
            acc += nums[i];
        }
        -1
    }
}

fn main() {
    // println!("{} {}", 3 % 2, (-3) % 2);
    let nums = vec![1, 7, 3, 6, 5, 6];
    println!("{}", Solution::pivot_index(nums));
}
