struct Solution {}

impl Solution {
    pub fn fair_candy_swap(a: Vec<i32>, b: Vec<i32>) -> Vec<i32> {
        let sum_a = a.iter().fold(0, |acc, x| acc + x);
        let sum_b = b.iter().fold(0, |acc, x| acc + x);
        let diff = sum_a - sum_b;
        use std::collections::HashSet;
        let se = a.iter().collect::<HashSet<_>>();
        // sum_a - x + y == sum_b - y + x 
        // diff = 2x - 2y
        // diff / 2 = x - y
        // x = diff / 2 + y
        for y in b {
            let target = diff / 2 + y;
            if se.contains(&target) {
                return vec![target, y];
            }
        }
        Vec::new()
    }
}

fn main() {
    let a = vec![1,2];
    let b = vec![2,3];
    println!("{:?}", Solution::fair_candy_swap(a, b));
}
