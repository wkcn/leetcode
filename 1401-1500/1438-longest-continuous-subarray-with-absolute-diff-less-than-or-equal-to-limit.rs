// 好题，滑动窗口，最小最大值
struct Solution {}

use std::collections::VecDeque;

impl Solution {
    pub fn longest_subarray(nums: Vec<i32>, limit: i32) -> i32 {
        let mut max_q = VecDeque::<i32>::new();
        let mut min_q = VecDeque::<i32>::new();
        let mut left = 0;
        let mut right = 0;
        let mut ans = 0;
        while right < nums.len() {
            while !max_q.is_empty() && *max_q.back().unwrap() < nums[right] {
                max_q.pop_back();
            }
            while !min_q.is_empty() && *min_q.back().unwrap() > nums[right] {
                min_q.pop_back();
            }
            max_q.push_back(nums[right]);
            min_q.push_back(nums[right]);
            while !max_q.is_empty() && !min_q.is_empty() && max_q.front().unwrap() - min_q.front().unwrap() > limit {
                if nums[left] == *max_q.front().unwrap() {
                    max_q.pop_front();
                }
                if nums[left] == *min_q.front().unwrap() {
                    min_q.pop_front();
                }
                left += 1;
            }
            ans = ans.max(right - left + 1);
            right += 1;
        }
        ans as i32
    }
}

fn main() {
    assert_eq!(Solution::longest_subarray(vec![8, 2, 4, 7], 4), 2);
}
