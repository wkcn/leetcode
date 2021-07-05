struct Solution {}

fn gcd(mut a: i32, mut b: i32) -> i32 {
    while b != 0 {
        let c = a % b;
        a = b;
        b = c;
    }
    a
}

impl Solution {
    pub fn max_points(points: Vec<Vec<i32>>) -> i32 {
        use std::collections::HashMap;
        let mut best = 0;
        for (i, p1) in points.iter().enumerate() {
            let (x1, y1) = (p1[0], p1[1]);

            // 记录一条直线出现的次数
            let mut cnts = HashMap::<(i32, i32, i32), i32>::new();
            // 从下标i + 1开始遍历
            for p2 in points.iter().skip(i + 1) {
                let (x2, y2) = (p2[0], p2[1]);
                let v3 = [y2 - y1, x1 - x2, x2 * y1 - x1 * y2];
                // 记录第一个非零元素的下标
                let mut nzi = -1;
                for k in 0..3 {
                    if v3[k] != 0 {
                        nzi = k as i32;
                        break;
                    }
                }
                let mut g = 1;
                if nzi != -1 {
                    // 约分
                    g = v3.iter().fold(v3[nzi as usize], |g, &x| {
                        // 不需要考虑0
                        if x == 0 {g}
                        else {gcd(g, x)}
                    });
                    // 由于v3[nzi]和gcd的结果可能是负数, 取绝对值
                    g = g.abs();
                    if v3[nzi as usize] < 0 {
                        // 让三元组的第一个非零元素为正数
                        g = -g;
                    }
                }
                // 进行约分并转为元组类型
                let v3 = (v3[0] / g, v3[1] / g, v3[2] / g);
                *cnts.entry(v3).or_insert(0) += 1;
                best = best.max(cnts[&v3]);
            }
        }
        best + 1
    }
}

fn main() {
    let points = vec![vec![1,1], vec![2,2], vec![3,3]];
    assert_eq!(Solution::max_points(points), 3);
    let points = vec![vec![1,1],vec![3,2],vec![5,3],vec![4,1],vec![2,3],vec![1,4]];
    assert_eq!(Solution::max_points(points), 4);
}
