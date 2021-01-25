struct Solution {}

impl Solution {
    pub fn find_max_average(nums: Vec<i32>, k: i32) -> f64 {
        let mut su = nums[..k as usize].iter().fold(0_f64, |acc, x| acc + *x as f64);
        nums[k as usize..].iter().zip(nums.iter()).fold(su, |acc, (x, old_x)| {
            su = su + (x - old_x) as f64;
            acc.max(su)
        }) / k as f64
    }
}

fn main() {
    let nums = vec![1,12,-5,-6,50,3];
    let k = 4;
    println!("{}", Solution::find_max_average(nums, k));
}
