struct Solution {}

impl Solution {
    pub fn num_identical_pairs(nums: Vec<i32>) -> i32 {
        use std::collections::HashMap;
        let mut ma = HashMap::new();
        for x in nums {
            *ma.entry(x).or_insert(0) += 1;
        }
        ma.values().map(|x| x * (x - 1) / 2).sum()
    }
}

fn main() {
    assert_eq!(Solution::num_identical_pairs(vec![1,2,3,1,1,3]), 4);
}
