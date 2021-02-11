// 分解问题，好好想一下TODO
struct Solution {}

impl Solution {
    pub fn subarrays_with_k_distinct(a: Vec<i32>, k: i32) -> i32 {
        // 将“恰好k个”转为“最多k个” - “最多k-1个”
        Solution::go(&a, k) - Solution::go(&a, k - 1)
    }
    fn go(a: &Vec<i32>, k: i32) -> i32 {
        use std::collections::HashMap;
        let mut cnts = HashMap::new();
        let mut left = 0;
        let mut diff_cnt = 0;
        let mut out = 0;
        // [left, right]
        for right in 0..a.len() {
            let cnt = cnts.entry(a[right]).or_insert(0);
            *cnt += 1;
            if *cnt == 1 {
                diff_cnt += 1;
            }
            while diff_cnt > k {
                let bc = cnts.get_mut(&a[left]).unwrap();
                *bc -= 1;
                if *bc == 0 {
                    diff_cnt -= 1;
                }
                left += 1;
            }
            out += right - left + 1;
            // println!("{:?} | {} {}, diff cnt: {}", cnts, left, right, diff_cnt);
        }
        out as i32
    }
}

fn main() {
    let a = vec![1,2,1,2,3];
    let k = 2;
    assert_eq!(Solution::subarrays_with_k_distinct(a, k), 7);

    let a = vec![1,2,1,3,4];
    let k = 3;
    assert_eq!(Solution::subarrays_with_k_distinct(a, k), 3);
}
