struct Solution {}

impl Solution {
    pub fn is_perfect_square(num: i32) -> bool {
        let mut lo = 1;
        let mut hi = num / 2 + 2;
        while lo < hi {
            let mid = lo + ((hi - lo) >> 1);
            if mid < num / mid {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        lo * lo == num
    }
}

fn main() {
    let num = 16;
    assert_eq!(Solution::is_perfect_square(num), true);

    let num = 14;
    assert_eq!(Solution::is_perfect_square(num), false);
}
