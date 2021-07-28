struct Solution {}

impl Solution {
    pub fn change(amount: i32, coins: Vec<i32>) -> i32 {
        let mut dp = vec![0; (amount + 1) as usize];
        dp[0] = 1;
        for x in coins {
            for i in x..=amount {
                dp[i as usize] += dp[(i - x) as usize]
            }
        }
        dp[amount as usize]
    }
}

fn main() {
    assert_eq!(Solution::change(5, vec![1,2,5]), 4);
}
