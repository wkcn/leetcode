struct Solution {}

impl Solution {
    pub fn is_monotonic(a: Vec<i32>) -> bool {
        use std::cmp::Ordering;
        let mut order = Ordering::Equal;
        for i in 1..a.len() {
            let o = a[i - 1].cmp(&a[i]);
            // 需要判断！
            if o != Ordering::Equal {
                if order != Ordering::Equal && order != o {
                    return false;
                }
                order = o;
            }
        }
        true
    }
}

fn main() {
    assert_eq!(Solution::is_monotonic(vec![1,2,2,3]), true);
    assert_eq!(Solution::is_monotonic(vec![6,5,4,4]), true);
    assert_eq!(Solution::is_monotonic(vec![1,3,2]), false);
}
