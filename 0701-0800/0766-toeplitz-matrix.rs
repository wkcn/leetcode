struct Solution {}

impl Solution {
    pub fn is_toeplitz_matrix(matrix: Vec<Vec<i32>>) -> bool {
        let rows = matrix.len();
        let cols = matrix[0].len();
        for r in 1..rows {
            for c in 1..cols {
                if matrix[r][c] != matrix[r-1][c-1] {
                    return false;
                }
            }
        }
        true
    }
}

fn main() {
    assert_eq!(Solution::is_toeplitz_matrix(vec![vec![1,2,3,4], vec![5,1,2,3], vec![9,5,1,2]]), true);
    assert_eq!(Solution::is_toeplitz_matrix(vec![vec![1, 2], vec![2, 2]]), false);
}
