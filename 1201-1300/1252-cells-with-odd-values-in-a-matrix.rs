struct Solution {}

impl Solution {
    pub fn odd_cells(n: i32, m: i32, indices: Vec<Vec<i32>>) -> i32 {
        let mut rows = vec![0; n as usize];
        let mut cols = vec![0; m as usize];
        for v in indices.iter() {
            rows[v[0] as usize] += 1;
            cols[v[1] as usize] += 1;
        }
        let row_even_cnt = rows.iter().filter(|&x| x % 2 == 0).count();
        let col_even_cnt = cols.iter().filter(|&x| x % 2 == 0).count();
        ((row_even_cnt * (cols.len() - col_even_cnt)) +
            (col_even_cnt * (rows.len() - row_even_cnt))) as i32
    }
}

fn main() {
    let n = 2;
    let m = 3;
    let indices = vec![vec![0,1],vec![1,1]];
    println!("{}", Solution::odd_cells(n, m, indices));

    let n = 2;
    let m = 2;
    let indices = vec![vec![1,1],vec![0,0]];
    println!("{}", Solution::odd_cells(n, m, indices));
}
