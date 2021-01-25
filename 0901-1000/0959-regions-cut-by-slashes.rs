struct Solution {}


struct UnionFind {
    parents: Vec<i32>,
    num_fields: i32,
}

impl UnionFind {
    fn new(n: i32) -> UnionFind {
        UnionFind {
            parents: (0..n).collect(), 
            num_fields: n
        }
    }
    fn connect(&mut self, a: i32, b: i32) -> bool {
        let pa = self.get_parent(a);
        let pb = self.get_parent(b);
        if pa != pb {
            self.parents[pa as usize] = pb;
            self.num_fields -= 1;
            true
        } else {
            false
        }
    }
    fn get_parent(&mut self, r: i32) -> i32 {
        if self.parents[r as usize] == r {
            r
        } else {
            let x = self.get_parent(self.parents[r as usize]);
            self.parents[r as usize] = x;
            x
        }
    }
}

impl Solution {
    pub fn regions_by_slashes(grid: Vec<String>) -> i32 {
        let rows = grid.len() as i32;
        if rows == 0 { return 0; }
        let cols = grid[0].len() as i32;
        /*
         * a grid:
         *     0
         *  1     3
         *     2
         */
        let mut uf = UnionFind::new(rows * cols * 4);
        for r in 0..rows {
            let cs: Vec<char> = grid[r as usize].chars().collect();
            for c in 0..cols {
                let b = (r * cols + c) * 4;
                match cs[c as usize] {
                    ' ' => {
                        uf.connect(b + 0, b + 1);
                        uf.connect(b + 1, b + 2);
                        uf.connect(b + 2, b + 3);
                        uf.connect(b + 3, b + 0);
                    }
                    '/' => {
                        uf.connect(b + 0, b + 1);
                        uf.connect(b + 2, b + 3);
                    }
                    '\\' => {
                        uf.connect(b + 1, b + 2);
                        uf.connect(b + 3, b + 0);
                    }
                    _ => {}
                }
                if c > 0 {
                    let lb = (r * cols + c - 1) * 4;
                    uf.connect(lb + 3, b + 1);
                }
                if r > 0 {
                    let lb = ((r - 1) * cols + c) * 4;
                    uf.connect(lb + 2, b + 0);
                }
            }
        }
        uf.num_fields
    }
}

fn main() {
    let grid: Vec<String> = vec![" /", "/ "].iter().map(|x| x.to_string()).collect();
    assert_eq!(Solution::regions_by_slashes(grid), 2);

    let grid: Vec<String> = vec!["\\/", "/\\"].iter().map(|x| x.to_string()).collect();
    assert_eq!(Solution::regions_by_slashes(grid), 4);

    let grid: Vec<String> = vec!["//", "/ "].iter().map(|x| x.to_string()).collect();
    assert_eq!(Solution::regions_by_slashes(grid), 3);
}
