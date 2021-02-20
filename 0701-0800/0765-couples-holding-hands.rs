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
    pub fn min_swaps_couples(row: Vec<i32>) -> i32 {
        let n = row.len() / 2;
        let mut uf = UnionFind::new(n as i32);
        for i in 0..n {
            let (a, b) = (row[i * 2] as i32 / 2, row[i * 2 + 1] as i32 / 2);
            uf.connect(a, b);
        }
        (0..n).filter(|&x| uf.parents[x] == x as i32).map(|x| uf.sizes[x] as i32 - 1).sum()
    }
}

fn main() {
    let row = vec![0, 2, 1, 3];
    println!("{}", Solution::min_swaps_couples(row));

    let row = vec![3, 2, 0, 1];
    println!("{}", Solution::min_swaps_couples(row));
}
