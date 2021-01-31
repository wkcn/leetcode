struct Solution {}

impl Solution {
    pub fn find_unsorted_subarray(nums: Vec<i32>) -> i32 {
        if nums.is_empty() {
            return 0;
        }
        let mut i: usize = 1;
        while i < nums.len() && nums[i - 1] <= nums[i] {
            i += 1;
        }
        // nums[..i]都是有序的
        for i2 in i..nums.len() {
            while i >= 1 && nums[i2] < nums[i - 1] {
                i -= 1;
            }
            if i  < 1 {
                break;
            }
        }
        // nums[j..]是有序的
        // nums.len() >= 1
        let mut j = nums.len() - 1;
        while j >= 1 && nums[j - 1] <= nums[j] {
            j -= 1;
        }
        if j > 0 {
            for j2 in 0..j {
                while j < nums.len() && nums[j2] > nums[j] {
                    j += 1;
                }
                if j >= nums.len() {
                    break;
                }
            }
                
        }
        if j < i {
            return 0;
        }
        (j - i) as i32
    }
}

fn main() {
    let nums = vec![2,6,4,8,10,9,15];
    println!("{}", Solution::find_unsorted_subarray(nums));

    let nums = vec![1,2,3,4];
    println!("{}", Solution::find_unsorted_subarray(nums));

    let nums = vec![1];
    println!("{}", Solution::find_unsorted_subarray(nums));
}
