struct Solution {}

impl Solution {
    pub fn get_row(row_index: i32) -> Vec<i32> {
        let k = row_index as usize + 1;
        let mut ans = vec![1; k];
        for i in 3..=k as usize {
            let mut last = 1;
            for j in 1..i - 1 {
                let y = ans[j] + last;
                last = ans[j];
                ans[j] = y;
            }
        }
        ans
    }
}

fn main() {
    for k in 0..=5 {
        println!("{:?}", Solution::get_row(k));
    }
}
