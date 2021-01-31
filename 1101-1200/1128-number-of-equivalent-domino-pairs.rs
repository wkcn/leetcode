struct Solution {}

impl Solution {
    pub fn num_equiv_domino_pairs(dominoes: Vec<Vec<i32>>) -> i32 {
        use std::collections::HashMap;
        let mut ma = HashMap::new();
        dominoes.iter().fold(0, |acc, x| {
            let y = if x[0] < x[1] {
                (x[0], x[1])
            } else { (x[1], x[0]) };
            // &mut
            let cnt = ma.entry(y).or_insert(0);
            let r = acc + *cnt;
            *cnt += 1;
            r
        })
    }
}

fn main() {
    let dominoes = vec![vec![1,2],vec![2,1],vec![3,4],vec![5,6]];
    println!("{}", Solution::num_equiv_domino_pairs(dominoes));
}
