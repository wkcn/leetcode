struct Solution {}

impl Solution {
    pub fn construct_rectangle(area: i32) -> Vec<i32> {
        for i in (1..=(area as f32).sqrt() as i32).rev() {
            if area % i == 0 {
                return vec![area / i, i];
            }
        }
        vec![-1; 2]
    }
}

fn main() {
    let n = 4;
    println!("{:?}", Solution::construct_rectangle(n));
    let n = 8;
    println!("{:?}", Solution::construct_rectangle(n));
}
