struct Solution {}

impl Solution {
    pub fn min_time_to_visit_all_points(points: Vec<Vec<i32>>) -> i32 {
        let mut ans = 0;
        for i in 0..points.len() - 1 {
            // 这里也等于取x或y绝对值的最大值
            // max(dx.abs(), dy.abs())
            let dx = (points[i + 1][0] - points[i][0]).abs();
            let dy = (points[i + 1][1] - points[i][1]).abs();
            // ans += dx.min(dy) + (dy - dx).abs();
            ans += dx.max(dy);
        }
        ans
    }
}

fn main() {
    assert_eq!(Solution::min_time_to_visit_all_points(vec![vec![1,1], vec![3,4], vec![-1, 0]]), 7);
}
