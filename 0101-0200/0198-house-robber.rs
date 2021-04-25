struct Solution {}
struct Solution2 {}

impl Solution2 {
    pub fn rob(nums: Vec<i32>) -> i32 {
        if nums.is_empty() {
            return 0;
        }
        let mut rob = nums[0];
        let mut norob = 0;
        for x in nums[1..].iter() {
            let old_rob = rob;
            rob = norob + x;
            norob = norob.max(old_rob);
        }
        rob.max(norob)
    }
}

impl Solution {
    pub fn rob(nums: Vec<i32>) -> i32 {
        if nums.len() <= 2 {
            return *nums.iter().max().unwrap_or(&0); 
        }
        let mut two = nums[0];
        let mut one = nums[0].max(nums[1]);
        for x in nums[2..].iter() {
            let old_one = one;
            // 注意这里
            one = (two + x).max(one);
            two = old_one;
        }
        one.max(two)
    }
}


fn main() {
    assert_eq!(Solution::rob(vec![1, 2, 3, 1]), 4);
    assert_eq!(Solution::rob(vec![2, 7, 9, 3, 1]), 12);
    assert_eq!(Solution::rob(vec![2, 1, 1, 2]), 4);
}
