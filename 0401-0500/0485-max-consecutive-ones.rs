struct Solution {}

impl Solution {
    pub fn find_max_consecutive_ones(nums: Vec<i32>) -> i32 {
        let mut ans = 0;
        let mut left = 0;
        while left < nums.len() {
            while left < nums.len() && nums[left] != 1 {
                left += 1;
            }
            // 如果left出界，需要break掉
            if left >= nums.len() {
                break;
            }
            let mut right = left + 1;
            while right < nums.len() && nums[right] == 1 {
                right += 1;
            }
            ans = ans.max(right - left);
            left = right;
        }
        ans as i32
    }
}

fn main() {
    let nums = vec![1, 1, 0, 1, 1, 1];
    assert_eq!(Solution::find_max_consecutive_ones(nums), 3);

    let nums = vec![0];
    assert_eq!(Solution::find_max_consecutive_ones(nums), 0);

    let nums = vec![1];
    assert_eq!(Solution::find_max_consecutive_ones(nums), 1);
}
