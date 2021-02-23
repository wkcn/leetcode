struct Solution {}

impl Solution {
    pub fn subtract_product_and_sum(n: i32) -> i32 {
        let mut n = n;
        let mut vs = Vec::new();
        if n == 0 {
            vs.push(0);
        } else {
            while n > 0 {
                vs.push(n % 10);
                n /= 10;
            }
        }
        let a = vs.iter().fold(1, |acc, x| acc * x);
        let b = vs.iter().fold(0, |acc, x| acc + x);
        a - b
    }
}

fn main() {
    assert_eq!(Solution::subtract_product_and_sum(234), 15);
}
