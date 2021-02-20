struct Solution {}

impl Solution {
    pub fn decompress_rl_elist(nums: Vec<i32>) -> Vec<i32> {
        nums.chunks(2).map(|x| {
            vec![x[1]; x[0] as usize]
        }).flatten().collect()
    }
}

fn main() {
    assert_eq!(Solution::decompress_rl_elist(vec![1, 2, 3, 4]), vec![2, 4, 4, 4]);
}
