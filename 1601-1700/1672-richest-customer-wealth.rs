struct Solution {}

impl Solution {
    pub fn maximum_wealth(accounts: Vec<Vec<i32>>) -> i32 {
        accounts.iter().map(|x| x.iter().sum()).max().unwrap_or_default()
    }
}

fn main() {
    assert_eq!(Solution::maximum_wealth(vec![]), 0);
    assert_eq!(Solution::maximum_wealth(vec![vec![1,2,3], vec![3,2,1]]), 6);
}
