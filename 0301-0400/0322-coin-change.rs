struct Solution {}

impl Solution {
    pub fn coin_change2(coins: Vec<i32>, amount: i32) -> i32 {
        let mut dp = vec![i32::max_value(); (amount + 1) as usize];
        dp[0] = 0;
        for i in 0..amount {
            if dp[i as usize] != i32::max_value() {
                for x in coins.iter() {
                    // i + x may be overflow
                    if i <= amount - x {
                        let target = i + x;
                        dp[target as usize] = dp[target as usize].min(dp[i as usize] + 1);
                    }
                }
            }
        }
        if dp[amount as usize] == i32::max_value() {-1}
        else {dp[amount as usize]}
    }

    pub fn coin_change(coins: Vec<i32>, amount: i32) -> i32 {
        let mut dp = vec![i32::max_value(); (amount + 1) as usize];
        dp[0] = 0;
        for x in coins {
            for i in 0..=(amount - x) {
                if dp[i as usize] != i32::max_value() {
                    dp[(i + x) as usize] = dp[(i + x) as usize].min(dp[i as usize] + 1);
                }
            }
        }
        if dp[amount as usize] == i32::max_value() {-1}
        else {dp[amount as usize]}
    }
}

fn main() {
    let coins = vec![1,2,5];
    assert_eq!(Solution::coin_change(coins, 11), 3);
}
