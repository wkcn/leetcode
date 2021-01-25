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
    pub fn make_connected(n: i32, connections: Vec<Vec<i32>>) -> i32 {
        let mut uf = UnionFind::new(n);
        let mut nb = 0;  // 多余的边
        for edges in connections.iter() {
            if !uf.connect(edges[0], edges[1]) {
                nb += 1;
            }
        }
        // 记连通域数量为uf.num_fields, 需要uf.num_fields - 1条边才能全部连通
        if nb >= uf.num_fields - 1 {
            return uf.num_fields - 1;
        }
        -1
    }
}

fn main() {
    let n = 4;
    let connections = vec![vec![0,1],vec![0,2],vec![1,2]];
    assert_eq!(Solution::make_connected(n, connections), 1);

    let n = 6;
    let connections = vec![vec![0,1],vec![0,2],vec![0,3],vec![1,2],vec![1,3]];
    assert_eq!(Solution::make_connected(n, connections), 2);
    
    let n = 6;
    let connections = vec![vec![0,1],vec![0,2],vec![0,3],vec![1,2]];
    assert_eq!(Solution::make_connected(n, connections), -1);

    let n = 5;
    let connections = vec![vec![0,1],vec![0,2],vec![3,4],vec![2,3]];
    assert_eq!(Solution::make_connected(n, connections), 0);
}
