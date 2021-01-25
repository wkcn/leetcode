struct Solution {}

use std::collections::HashSet;
impl Solution {
    pub fn distribute_candies(candy_type: Vec<i32>) -> i32 {
        let mut hs = HashSet::new();
        let _: Vec<_> = candy_type.iter().map(|x| hs.insert(x)).collect();
        ((candy_type.len() / 2).min(hs.len())) as i32
    }
}


fn main() {
    let candies = vec![1, 1, 2, 2, 3, 3];
    println!("{}", Solution::distribute_candies(candies));
}
