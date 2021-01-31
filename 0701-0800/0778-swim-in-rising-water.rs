// 和1631差不多
// TODO: Disjkstra
struct Solution2 {}

impl Solution2 {
    pub fn swim_in_water(grid: Vec<Vec<i32>>) -> i32 {
        if grid.is_empty() || grid[0].is_empty() {
            return 0;
        }
        let mut ma = grid[0][0];
        for v in grid.iter() {
            for x in v {
                ma = ma.max(*x);
            }
        }
        // 注意初始值一定要大于等于grid[0][0]
        let (mut lo, mut hi) = (grid[0][0], ma + 1);
        while lo < hi {
            let mid = lo + ((hi - lo) >> 1);
            if Self::check(&grid, mid) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        lo
    }
    fn check(heights: &Vec<Vec<i32>>, t: i32) -> bool {
        let (m, n) = (heights.len(), heights[0].len());
        use std::collections::VecDeque;
        let mut q = VecDeque::<(i32, i32)>::new();
        let mut vis = vec![vec![false; n]; m];
        q.push_back((0, 0));
        vis[0][0] = true;
        while !q.is_empty() {
            let (r, c) = q.pop_front().unwrap();
            if r == m as i32 - 1 && c == n as i32 - 1 {
                return true;
            }
            for (dr, dc) in [(1, 0), (-1, 0), (0, 1), (0, -1)].iter() {
                let nr: usize = (r + dr) as usize;
                let nc: usize = (c + dc) as usize;
                if nr < m && nc < n && !vis[nr][nc] {
                    if heights[nr][nc] <= t {
                        vis[nr][nc] = true;
                        q.push_back((nr as i32, nc as i32));
                    }
                }
            }
        }
        false
    }
}

struct Solution {}

#[derive(Clone)]
struct UnionFind {
    parents: Vec<i32>,
    sizes: Vec<i32>,
    num_fields: i32,
}

impl UnionFind {
    fn new(n: i32) -> UnionFind {
        UnionFind {
            parents: (0..n).collect(),
            sizes: vec![1; n as usize],
            num_fields: n
        }
    }
    fn connect(&mut self, a: i32, b: i32) -> bool {
        let mut pa = self.get_parent(a);
        let mut pb = self.get_parent(b);
        if pa != pb {
            if self.sizes[pa as usize] > self.sizes[pb as usize] {
                std::mem::swap(&mut pa, &mut pb);
            }
            self.parents[pa as usize] = pb;
            self.sizes[pb as usize] += self.sizes[pa as usize];
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
    pub fn swim_in_water(grid: Vec<Vec<i32>>) -> i32 {
        let (rows, cols) = (grid.len(), grid[0].len());
        let P = |r, c| {
            (r * cols + c) as i32
        };
        let mut edges = Vec::new();
        for r in 0..rows {
            for c in 0..cols {
                let a = grid[r][c];
                if r > 0 {
                    // (r-1, c)
                    let b = grid[r - 1][c];
                    edges.push((P(r, c), P(r - 1, c), i32::max(a, b)));
                }
                if c > 0 {
                    let b = grid[r][c - 1];
                    edges.push((P(r, c), P(r, c - 1), i32::max(a, b)));
                }
            }
        }
        edges.sort_unstable_by(|x, y| x.2.cmp(&y.2));
        let mut uf = UnionFind::new((rows * cols) as i32);
        for (a, b, dis) in edges {
            uf.connect(a, b);
            if uf.get_parent(0) == uf.get_parent((rows * cols - 1) as i32) {
                return dis;
            }
        }
        0
    }
}


fn main() {
    let grid = vec![vec![0,2],vec![1,3]];
    println!("{}", Solution::swim_in_water(grid));

    let grid = vec![vec![3,2],vec![0,1]];
    println!("{}", Solution::swim_in_water(grid));
}
