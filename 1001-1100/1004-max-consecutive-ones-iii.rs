struct Solution2 {}

impl Solution2 {
    pub fn longest_ones(a: Vec<i32>, k: i32) -> i32 {
        let mut left = 0;
        let mut right = 0;
        let mut ans = 0;
        let mut flip = 0;
        // [left, right)
        while right < a.len() {
            if a[right] == 0 {
                if flip < k {
                    flip += 1;
                    right += 1;
                } else {
                    if k == 0 {
                        left = right + 1;
                        right += 1;
                    } else {
                        while left < right {
                            if a[left] == 0 {
                                left += 1;
                                break;
                            }
                            left += 1;
                        }
                        right += 1;
                    }
                }
            } else {
                right += 1;
            }
            ans = ans.max(right - left);
        }
        ans as i32
    }
}

struct Solution {}

impl Solution {
    pub fn longest_ones(a: Vec<i32>, k: i32) -> i32 {
        let (mut left, mut right) = (0, 0);
        let mut ans = 0;
        let mut flip = 0;
        let k = k as usize;
        while right < a.len() {
            if a[right] == 0 {
                flip += 1;
            }
            right += 1;
            /*
            while flip > k {
                if a[left] == 0 {
                    flip -= 1;
                }
                left += 1;
            }
            */
            if flip > k {
                while a[left] == 1 {
                    left += 1;
                }
                left += 1;
                flip -= 1;
            }

            ans = ans.max(right - left);
        }
        ans as i32
    }
}

fn main() {
    assert_eq!(Solution::longest_ones(vec![0,0,1,1,1,0,0], 0), 3);
    assert_eq!(Solution::longest_ones(vec![0, 0, 0], 0), 0);
    assert_eq!(Solution::longest_ones(vec![1,1,1,0,0,0,1,1,1,1,0], 2), 6);
    assert_eq!(Solution::longest_ones(vec![0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], 3), 10);
}
