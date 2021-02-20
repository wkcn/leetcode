struct Solution {}

impl Solution {
    pub fn find_disappeared_numbers(nums: Vec<i32>) -> Vec<i32> {
        let mut nums = nums;
        for i in 0..nums.len() {
            // i + 1
            while nums[i] != (i + 1) as i32 && nums[(nums[i] - 1) as usize] != nums[i] {
                let j = (nums[i] - 1) as usize;
                nums.swap(i, j);
            }
        }
        (1_i32..=nums.len() as i32).filter(|&x| nums[(x - 1) as usize] != x).collect()
    }
}

fn main() {
    let nums = vec![4, 3, 2, 7, 8, 2, 3, 1];
    println!("{:?}", Solution::find_disappeared_numbers(nums));
}
