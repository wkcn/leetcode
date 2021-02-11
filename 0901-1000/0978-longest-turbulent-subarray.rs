// TODO: DP + 空间压缩
struct Solution {}

use std::cmp::Ordering::{Equal};

impl Solution {
    pub fn max_turbulence_size(arr: Vec<i32>) -> i32 {
        if arr.len() <= 1 {
            return arr.len() as i32;
        }
        let mut state = Equal;
        let mut left = 0;
        let mut right = 1;
        let mut ans = 0;
        while right < arr.len() {
            let cur = arr[right - 1].cmp(&arr[right]);
            if cur == Equal {
                left = right;
                state = Equal;
            } else {
                if state == cur {
                    // 如果是符号相同且不是等于，可以保留index为right - 1的字符
                    left = right - 1;
                } else {
                    state = cur;
                }
            }
            ans = ans.max(right - left + 1);
            // println!("V: {} {} {:?}", left, right, state);
            right += 1;
        }
        ans as i32
    }
}

fn main() {
    let arr = vec![9, 4, 2, 10, 7, 8, 8, 1, 9];
    assert_eq!(Solution::max_turbulence_size(arr), 5);
    let arr = vec![4, 8, 12, 16];
    assert_eq!(Solution::max_turbulence_size(arr), 2);
    let arr = vec![100];
    assert_eq!(Solution::max_turbulence_size(arr), 1);
}
