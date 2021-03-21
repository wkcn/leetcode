struct Solution {}
impl Solution {
    pub fn set_zeroes(matrix: &mut Vec<Vec<i32>>) {
        if matrix.is_empty() {
            return
        }
        let first_row_is_zero = matrix[0].iter().any(|x| *x == 0);
        for r in 1..matrix.len() {
            for c in 0..matrix[r].len() {
                if matrix[r][c] == 0 {
                    matrix[r][0] = 0;
                    matrix[0][c] = 0;
                }
            }
        }
        for r in 1..matrix.len() {
            for c in 1..matrix[r].len() {
                if matrix[r][0] == 0 || matrix[0][c] == 0 {
                    matrix[r][c] = 0;
                }
            }
        }
        if matrix[0][0] == 0 {
            for r in 1..matrix.len() {
                matrix[r][0] = 0;
            }
        }
        if first_row_is_zero {
            // 全设为0, 包括matrix[0][0]
            for c in 0..matrix[0].len() {
                matrix[0][c] = 0;
            }
        }
            
    }
}

fn main() {
    let mut matrix = vec![vec![1,1,1], vec![1,0,1], vec![1,1,1]];
    Solution::set_zeroes(&mut matrix);
    assert_eq!(matrix, vec![vec![1,0,1], vec![0,0,0], vec![1,0,1]]);

    let mut matrix = vec![vec![1,0]];
    Solution::set_zeroes(&mut matrix);
    assert_eq!(matrix, vec![vec![0, 0]]);
}
