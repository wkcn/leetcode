// TODO: 理解这题的证明和其他方法
struct Solution {}

use std::collections::HashMap;
type BufT = HashMap<(i32, i32), i32>;
impl Solution {
    pub fn stone_game(piles: Vec<i32>) -> bool {
        let mut buf: BufT = HashMap::new(); 
        return Self::go(&piles, 0, piles.len() as i32 - 1, &mut buf) > 0;
    }
    fn go(piles: &Vec<i32>, i: i32, j: i32, mut buf: &mut BufT) -> i32 {
        if i > j {
            return 0;
        }
        if let Some(e) = buf.get(&(i, j)) {
            return *e;
        }
        let v = i32::max(piles[i as usize] - Self::go(&piles, i + 1, j, &mut buf),
                         piles[j as usize] - Self::go(&piles, i, j - 1, &mut buf));
        buf.insert((i, j), v);
        return v;
    }
}

fn main() {
    assert_eq!(Solution::stone_game(vec![5, 3, 4, 5]), true);
    assert_eq!(Solution::stone_game(vec![3, 7, 2, 3]), true);
}
