struct Solution {}

impl Solution {
    pub fn next_greater_elements(nums: Vec<i32>) -> Vec<i32> {
        let n = nums.len();
        let mut ans = vec![-1; n];
        let mut st: Vec<usize> = Vec::new();  // 从大到小
        for t in 0..2 {
            for (i, x) in nums.iter().enumerate() {
                while !st.is_empty() && nums[*st.last().unwrap()] < *x {
                    ans[*st.last().unwrap()] = *x;
                    st.pop();
                }
                if t == 0 {
                    st.push(i);
                }
            }
        }
        ans
    }
}

fn main() {
    assert_eq!(Solution::next_greater_elements(vec![1,2,1]), vec![2,-1,2]);
}
