struct Solution {}

impl Solution {
    pub fn reverse(mut x: i32) -> i32 {
        let minus = x < 0;
        if !minus {
            x = -x;
        }
        let mut v = 0;
        while x < 0 {
            if v < i32::min_value() / 10 {
                return 0;
            }
            v *= 10;
            let r = x % 10;
            if v < i32::min_value() - r {
                return 0;
            }
            v += r;
            x /= 10;
        }
        if minus {
            return v;
        }
        if v == i32::min_value() {
            return 0;
        }
        -v
    }
}

fn main() {
    assert_eq!(Solution::reverse(123), 321);
    assert_eq!(Solution::reverse(-123), -321);
    assert_eq!(Solution::reverse(120), 21);
    assert_eq!(Solution::reverse(0), 0);
}
