struct Solution {}

impl Solution {
    pub fn diagonal_sum(mat: Vec<Vec<i32>>) -> i32 {
        let n = mat.len();
        let mut ans = 0;
        for i in 0..n {
            ans += mat[i][i];
            ans += mat[i][n - 1 - i];
        }
        if n % 2 == 1 {
            ans -= mat[n / 2][n / 2];
        }
        ans
    }
}

fn main() {
    assert_eq!(Solution::diagonal_sum(vec![vec![1,2,3], vec![4,5,6], vec![7,8,9]]), 25);
}
