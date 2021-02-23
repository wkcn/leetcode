struct Solution {}

impl Solution {
    pub fn sum_of_unique(nums: Vec<i32>) -> i32 {
        use std::collections::HashMap;
        let mut cnts = HashMap::new();
        for x in nums {
            *cnts.entry(x).or_insert(0) += 1;
        }
        let mut ans = 0;
        for (k, v) in cnts {
            if v == 1 {
                ans += k;
            }
        }
        ans
    }
}

fn main() {
    assert_eq!(Solution::sum_of_unique(vec![1,2,3,2]), 4);
}
