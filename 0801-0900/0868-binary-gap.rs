struct Solution {}

impl Solution {
    pub fn binary_gap(n: i32) -> i32 {
        let mut t = -1;
        let mut n = n;
        let mut ans = 0;
        let mut i = 0;
        while n > 0 {
            if n % 2 == 1 {
                if t == -1 {
                    t = i;
                } else {
                    ans = ans.max(i - t);
                    t = i;
                }
                    
            }
            n /= 2;
            i += 1;
        }
        ans
    }
}

fn main() {
    assert_eq!(Solution::binary_gap(22), 2);
    assert_eq!(Solution::binary_gap(5), 2);
    assert_eq!(Solution::binary_gap(6), 1);
    assert_eq!(Solution::binary_gap(8), 0);
    assert_eq!(Solution::binary_gap(1), 0);
}
