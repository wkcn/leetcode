struct Solution {}

impl Solution {
    pub fn create_target_array(nums: Vec<i32>, index: Vec<i32>) -> Vec<i32> {
        let mut ans = Vec::with_capacity(nums.len());
        for (v, i) in nums.into_iter().zip(index.into_iter()) {
            ans.insert(i as usize, v);
        }
        ans
    }
}

fn main() {
    assert_eq!(Solution::create_target_array(vec![0,1,2,3,4], vec![0,1,2,2,1]), vec![0,4,1,3,2]);
}
