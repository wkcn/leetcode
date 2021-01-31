struct Solution {}

impl Solution {
    pub fn is_boomerang(points: Vec<Vec<i32>>) -> bool {
        // (x - x1) / (x2 - x1) != (y - y1) / (y2 - y1)
        // (x - x1) * (y2 - y1) != (y - y1) * (x2 - x1)
        let (x1, y1) = (points[0][0], points[0][1]);
        let (x2, y2) = (points[1][0], points[1][1]);
        let (x3, y3) = (points[2][0], points[2][1]);
        (x3 - x1) * (y2 - y1) != (y3 - y1) * (x2 - x1)
    }
}
