// 差分数组
struct Solution {}

impl Solution {
    pub fn min_k_bit_flips(a: Vec<i32>, k: i32) -> i32 {
        let n = a.len();
        let mut diff = vec![0; n];
        let mut flip = 0;
        let mut ans = 0;
        let k = k as usize;
        for i in 0..n {
            flip = (flip + diff[i]) % 2;
            if (a[i] + flip) % 2 == 0 {
                // 需要翻转
                if i + k <= n {
                    flip = 1 - flip;
                    if i + k < n {
                        diff[i + k] = 1 - diff[i + k];
                    }
                    ans += 1;
                } else {
                    return -1;
                }
            }
        }
        ans
    }
}

fn main() {
    assert_eq!(Solution::min_k_bit_flips(vec![0, 1, 0], 1), 2);
    assert_eq!(Solution::min_k_bit_flips(vec![1, 1, 0], 2), -1);
    assert_eq!(Solution::min_k_bit_flips(vec![0,0,0,1,0,1,1,0], 3), 3);
}
