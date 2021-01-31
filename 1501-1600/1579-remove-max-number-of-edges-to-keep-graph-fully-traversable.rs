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
    pub fn max_num_edges_to_remove(n: i32, edges: Vec<Vec<i32>>) -> i32 {
        // 注意：这个是无向图，独占边是独占的无向边！！
        // edges: [(type, u, v), ...]
        // type = 1, alice独占
        // type = 2, bob独占
        // type = 3, alice 和 bob 共用
        let mut common_edges = Vec::new();
        let mut alice_edges = Vec::new();
        let mut bob_edges = Vec::new();
        for e in edges.into_iter() {
            match e[0] {
                1 => alice_edges.push(e),
                2 => bob_edges.push(e),
                _ => common_edges.push(e),
            }
        }
        let mut uf = UnionFind::new(n);
        let mut ans = Solution::connect_edges(&mut uf, common_edges);

        let mut alice = uf.clone();
        let mut bob = uf;
        ans += Solution::connect_edges(&mut alice, alice_edges);
        if alice.num_fields > 1 {
            return -1;
        }
        ans += Solution::connect_edges(&mut bob, bob_edges);
        if bob.num_fields > 1 {
            return -1;
        }
        ans
    }
    fn connect_edges(uf: &mut UnionFind, edges: Vec<Vec<i32>>) -> i32 {
        // 返回多余的边
        let mut cnt = 0;
        for e in edges.into_iter() {
            let (u, v) = (e[1] - 1, e[2] - 1);
            if !uf.connect(u, v) {
                cnt += 1;
            }
        }
        cnt
    }
}

fn main() {
    let n = 4;
    let edges = vec![vec![3,1,2],vec![3,2,3],vec![1,1,3],vec![1,2,4],vec![1,1,2],vec![2,3,4]];
    assert_eq!(Solution::max_num_edges_to_remove(n, edges), 2);


    let n = 4;
    let edges = vec![vec![3,1,2],vec![3,2,3],vec![1,1,4],vec![2,1,4]];
    assert_eq!(Solution::max_num_edges_to_remove(n, edges), 0);

    let n = 4;
    let edges = vec![vec![3,2,3],vec![1,1,2],vec![2,3,4]];
    assert_eq!(Solution::max_num_edges_to_remove(n, edges), -1);
}
