struct Solution {}

impl Solution {
    pub fn largest_number(nums: Vec<i32>) -> String {
        let mut nums: Vec<_> = nums.iter().map(|x| format!("{}", x)).collect();
        nums.sort_unstable_by(|x, y| format!("{}{}", y, x).cmp(&format!("{}{}", x, y)));
        // 注意只有0的情况
        if nums[0] == "0" {
            return "0".to_string();
        }
        nums.concat()
    }
}

fn main() {
    let nums = vec![3,30,34,5,9];
    println!("{}", Solution::largest_number(nums));

    let nums = vec![0, 0];
    println!("{}", Solution::largest_number(nums));
}
