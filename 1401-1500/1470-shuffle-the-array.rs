struct Solution {}

impl Solution {
    pub fn shuffle(nums: Vec<i32>, n: i32) -> Vec<i32> {
        let n = n as usize;
        nums[..n].iter().zip(nums[n..].iter()).map(|x| vec![*x.0, *x.1]).flatten().collect()
    }
}

fn main() {
    assert_eq!(Solution::shuffle(vec![2,5,1,3,4,7], 3), vec![2,3,5,4,1,7]);
}
