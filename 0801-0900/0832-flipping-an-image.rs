struct Solution {}

impl Solution {
    pub fn flip_and_invert_image(a: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let rows = a.len();
        let cols = a[0].len();
        let mut a = a;
        for r in 0..rows {
            for c in 0..(cols / 2) {
                a[r].swap(c, cols - 1 - c);
            }
        }
        a.iter_mut().for_each(|r| r.iter_mut().for_each(|x| *x ^= 1 )); 
        a
    }
}

fn main() {
    assert_eq!(Solution::flip_and_invert_image(vec![vec![1,1,0],vec![1,0,1],vec![0,0,0]]),
               vec![vec![1,0,0],vec![0,1,0],vec![1,1,1]]);
    
}
