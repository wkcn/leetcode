struct Solution {}

struct UnionFind {
    parents: Vec<i32>,
    num_fields: i32,
}

impl UnionFind {
    fn new(n: i32) -> UnionFind {
        let mut uf = UnionFind {
            parents: Vec::new(),
            num_fields: n
        };
        for i in 0..n {
            uf.parents.push(i);
        }
        uf
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
    pub fn find_critical_and_pseudo_critical_edges(n: i32, edges: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        // n: the number of nodes
        // edges[i] = [fromi, toi, weighti]
        let mut ans: Vec<Vec<i32> > = vec![vec![]; 2];
        let mut uf: UnionFind = UnionFind::new(n);
        let mut edges = edges;
        for (i, e) in edges.iter_mut().enumerate() {
            e.push(i as i32);
        }
        // 排序后边的编号和index可能不一致！
        edges.sort_unstable_by(|a, b| a[2].cmp(&b[2]));
        let mut v = 0;
        for e in edges.iter() {
            if uf.connect(e[0], e[1]) {
                v += e[2];
            }
        }
        if uf.num_fields > 1 {
            // 没有生成树
            return ans;
        }
        // 找关键边
        for i in 0..edges.len() {
            let mut uf: UnionFind = UnionFind::new(n);
            let mut t = 0;
            for e in edges.iter() {
                if e[3] as usize != i && uf.connect(e[0], e[1]) {
                    t += e[2];
                    // println!("{}: {} {}", i, e[0], e[1])
                }
            }
            // println!("{}: t={} v={} f={}", i, t, v, uf.num_fields);

            // 不构成连通图时也算关键边???
            if uf.num_fields > 1 || t > v {
                ans[0].push(i as i32);
            }

            // 1. 出现在最小生成树，也就是说先加入这条边，有t == v
            // 2. 不会出现在所有最小生成树，说的是删掉这条边后，仍然有t == v
            if uf.num_fields == 1 && t == v {
                //println!("Try: {}", i);
                let mut uf: UnionFind = UnionFind::new(n);
                let mut t = 0;
                for e in edges.iter() {
                    if e[3] as usize == i {
                        uf.connect(e[0], e[1]);
                        t += e[2];
                        break;
                    }
                }
                for e in edges.iter() {
                    if uf.connect(e[0], e[1]) {
                        t += e[2];
                    }
                }
                //println!("F: {}, t: {}, v: {}", uf.num_fields, t, v);
                if t == v {
                    ans[1].push(i as i32);
                }
            }
        }
        ans
    }
}

fn main() {
    /*
    let n = 5;
    let edges = vec![vec![0,1,1],vec![1,2,1],vec![2,3,2],
                     vec![0,3,2],vec![0,4,3],vec![3,4,3],
                     vec![1,4,6]];
    let ans = Solution::find_critical_and_pseudo_critical_edges(n, edges);
    println!("{:?}", ans);
    */

    let n = 6;
    let edges = vec![vec![0,1,1],vec![1,2,1],vec![0,2,1],vec![2,3,4],vec![3,4,2],vec![3,5,2],vec![4,5,2]];
    let ans = Solution::find_critical_and_pseudo_critical_edges(n, edges);
    println!("{:?}", ans);
}
