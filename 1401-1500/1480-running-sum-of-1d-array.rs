struct Solution {}

impl Solution {
    pub fn running_sum(nums: Vec<i32>) -> Vec<i32> {
        let mut ans = Vec::new();
        nums.iter().fold(0, |acc, x| {
            let v = acc + x;
            ans.push(v);
            v
        });
        ans
    }
}

fn main() {
    assert_eq!(Solution::running_sum(vec![1,2,3,4]), vec![1,3,6,10]);
}
