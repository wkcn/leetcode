struct Solution {}

impl Solution {
    pub fn can_make_arithmetic_progression(arr: Vec<i32>) -> bool {
        let mut arr = arr;
        arr.sort_unstable();
        let diff: Vec<i32> = arr.windows(2).map(|x| x[0] - x[1]).collect();
        diff.iter().all(|&x| x == diff[0])
    }
}

fn main() {
    let arr = vec![3,5,1];    
    println!("{}", Solution::can_make_arithmetic_progression(arr));
}
