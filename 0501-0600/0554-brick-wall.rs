struct Solution {}

impl Solution {
    pub fn least_bricks(wall: Vec<Vec<i32>>) -> i32 {
        // 穿过的砖块最少 = 穿过的缝隙最多
        use std::collections::HashMap;
        let mut ma = HashMap::new();
        for w in wall.iter() {
            let mut v = 0;
            for b in w[..w.len() - 1].iter() {
                v += b;
                *ma.entry(v).or_insert(0) += 1;
            }
        }
        let mut a = 0;
        for &v in ma.values() {
            a = a.max(v);
        }
        (wall.len() - a) as i32
    }
}

fn main() {
    let wall = vec![vec![1,2,2,1],vec![3,1,2],vec![1,3,2],vec![2,4],vec![3,1,2],vec![1,3,1,1]];
    assert_eq!(Solution::least_bricks(wall), 2);
}
