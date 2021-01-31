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
    pub fn num_similar_groups(strs: Vec<String>) -> i32 {
        let strs: Vec<_> = strs.iter().map(|x| x.chars().collect::<Vec<_>>()).collect();
        let n = strs.len();
        let mut uf = UnionFind::new(n as i32);
        for i in 0..n {
            for j in i+1..n {
                if Solution::is_similar(&strs[i], &strs[j]) {
                    uf.connect(i as i32, j as i32);
                }
            }
        }
        uf.num_fields
    }
    fn is_similar(a: &Vec<char>, b: &Vec<char>) -> bool {
        if a.len() != b.len() {
            return false;
        }
        let mut diff_i = -1;
        let mut diff_j = -1;
        for t in 0..a.len() {
            if a[t] != b[t] {
                if diff_i == -1 {
                    diff_i = t as i32;
                } else if diff_j == -1 {
                    diff_j = t as i32;
                } else { return false; }
            }
        }
        if diff_i == -1 && diff_j == -1 {
            return true;
        }
        if diff_i == -1 || diff_j == -1 {
            return false;
        }
        a[diff_i as usize] == b[diff_j as usize] &&
            a[diff_j as usize] == b[diff_i as usize]
    }
}

fn main() {
    let strs = ["tars","rats","arts","star"].iter().map(|x| x.to_string()).collect();
    println!("{}", Solution::num_similar_groups(strs));
}
