// todo: 滑动窗口
struct Solution {}

impl Solution {
    pub fn longest_substring(s: String, k: i32) -> i32 {
        Self::dfs(&s.bytes().collect::<Vec<u8>>(), k, 0, s.len())
    }
    fn dfs(s: &Vec<u8>, k: i32, start: usize, end: usize) -> i32 {
        if end - start < k as usize {
            return 0;
        }
        let mut cnts = vec![0; 26];
        // 注意区间！
        for i in start..end {
            cnts[(s[i] - b'a') as usize] += 1;
        }
        let mut split = -1_i32;
        for i in 0..26 {
            // 还要要求字符存在！
            if cnts[i] > 0 && cnts[i] < k {
                split = i as i32 + b'a' as i32; 
            }
        }
        if split ==  -1 {
            return (end - start) as i32;
        }
        let split = split as u8;
        let mut left = start;
        let mut ret = 0;
        while left < end {
            while left < end && s[left] == split {
                left += 1;
            }
            let mut right = left + 1;
            while right < end && s[right] != split {
                right += 1;
            }
            ret = ret.max(Self::dfs(s, k, left, right));
            left = right;
        }
        ret
    }
}

fn main() {
    assert_eq!(Solution::longest_substring("aaabb".to_string(), 3), 3);
    assert_eq!(Solution::longest_substring("ababbc".to_string(), 2), 5);
}
