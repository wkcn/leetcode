struct Solution {}

impl Solution {
    pub fn robot_sim(commands: Vec<i32>, obstacles: Vec<Vec<i32>>) -> i32 {
        use std::collections::HashSet;
        let se = obstacles.iter().map(|x| (x[0], x[1])).collect::<HashSet<_>>(); 
        let (mut x, mut y) = (0, 0);
        let mut d = 0;
        let mut ans = 0;
        let mut go = |dx, dy, step| {
            for _ in 0..step {
                let nx = x + dx;
                let ny = y + dy;
                if se.contains(&(nx, ny)) {
                    break;
                }
                x = nx;
                y = ny;
            }
            let v = x * x + y * y;
            ans = ans.max(v);
        };
        //   0
        // 1   3
        //   2
        for x in commands {
            match x {
                -2 => d = (d + 1) % 4,
                -1 => d = (d + 3) % 4,
                _  => {
                    match d {
                        0 => go(0, 1, x),
                        1 => go(-1, 0, x),
                        2 => go(0, -1, x),
                        3 => go(1, 0, x),
                        _ => (),
                    }
                },
            }
        }
        ans
    }
}

fn main() {
    let commands = vec![4,-1,4,-2,4];
    let obstacles = vec![vec![2,4]];
    println!("{}", Solution::robot_sim(commands, obstacles));
}
