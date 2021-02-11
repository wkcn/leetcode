// TODO: 窗口是固定长度的，试一下像题解一样简化算法
struct Solution {}

impl Solution {
    pub fn check_inclusion(s1: String, s2: String) -> bool {
        use std::collections::HashMap;
        let mut cnts = HashMap::new();
        for c in s1.bytes() {
            *cnts.entry(c).or_insert(0) += 1;
        }
        let mut cnt = cnts.len();
        let mut left = 0;  // [left, right)

        let s2 = s2.bytes().collect::<Vec<_>>();
        for right in 0..s2.len() {
            if let Some(r) = cnts.get_mut(&s2[right]) {
                // s2[right]有三种情况
                // 1. cnts需要的但数量不充足
                // 2. cnts不需要的
                //      让left = right, 重新计数
                // 3. cnts需要但数量已经充足的
                //      让left向右降到cnts刚好
                if *r > 0 {
                    // case 1
                    *r -= 1;
                    if *r == 0 {
                        cnt -= 1;
                        if cnt == 0 {
                            return true;
                        }
                    }
                } else {
                    // case 3
                    while s2[left] != s2[right] {
                        if let Some(p) = cnts.get_mut(&s2[left]) {
                            *p += 1;
                            if *p == 1 {
                                cnt += 1;
                            }
                        }
                        left += 1;
                    }
                    // 此时s2[left] == s2[right], 对应cnt == 0
                    left += 1;
                }
            } else {
                // case 2
                while left < right {
                    if let Some(p) = cnts.get_mut(&s2[left]) {
                        *p += 1;
                        if *p == 1 {
                            cnt += 1;
                        }
                    }
                    left += 1;
                }
            }
        }
        false
    }
}

fn main() {
    let s1 = "ab".to_string();
    let s2 = "eidbaooo".to_string();
    assert_eq!(Solution::check_inclusion(s1, s2), true);

    let s1= "ab".to_string();
    let s2 = "eidboaoo".to_string();
    assert_eq!(Solution::check_inclusion(s1, s2), false);
}
