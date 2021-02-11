struct Solution {}

impl Solution {
    pub fn max_score(card_points: Vec<i32>, k: i32) -> i32 {
        // left: [0, k]
        // left = k
        let mut su: i32 = card_points[..k as usize].iter().sum();
        let mut ans = su;
        for t in (0..k as usize).rev() {
            su = su - card_points[t] + card_points[card_points.len() - (k as usize - t)];
            ans = ans.max(su);
        }
        ans
    }
}

fn main() {
    let card_points = vec![1,2,3,4,5,6,1];
    let k = 3;
    println!("{}", Solution::max_score(card_points, k));
}
