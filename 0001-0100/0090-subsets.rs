struct Solution {}

impl Solution {
    pub fn subsets_with_dup(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut ans = Vec::new();
        let mut buf = vec![];
        let mut nums = nums;
        nums.sort_unstable();

        Solution::go(&mut ans, &nums, &mut buf, 0);
        ans
    }
    fn go(ans: &mut Vec<Vec<i32>>, nums: &Vec<i32>, buf: &mut Vec<i32>, start: usize) {
        ans.push(buf.to_vec());
        // (i, nums.len())
        for j in start..nums.len() {
            if j > start && nums[j - 1] == nums[j] {
                continue;
            }
            buf.push(nums[j]);
            Solution::go(ans, nums, buf, j + 1);
            buf.pop();
        }
    }
}

fn main() {
    let nums = vec![1, 2, 2];
    let ans = Solution::subsets_with_dup(nums);
    println!("{:?}", ans);
    println!("len = {}", ans.len());
}
