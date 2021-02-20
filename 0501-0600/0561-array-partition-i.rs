struct Solution {}

impl Solution {
    pub fn array_pair_sum(nums: Vec<i32>) -> i32 {
        // 最小的和次小的组合，才不会损失太大
        let mut nums = nums;
        nums.sort_unstable();
        nums.iter().step_by(2).sum()
    }
}

fn main() {
    assert_eq!(Solution::array_pair_sum(vec![1, 4, 3, 2]), 4);
    assert_eq!(Solution::array_pair_sum(vec![6, 2, 6, 5, 1, 2]), 9);
}
