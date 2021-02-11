// TODO: 证明过程
struct Solution {}

impl Solution {
    pub fn character_replacement(s: String, k: i32) -> i32 {
        let mut cnts = vec![0; 26];
        let mut i = 0;
        let mut j = 0;
        let s: Vec<_> = s.chars().collect();
        let mut maxn = 0;
        while j < s.len() {
            cnts[s[j] as usize - 'A' as usize] += 1;
            maxn = maxn.max(cnts[s[j] as usize - 'A' as usize]);
            j += 1;
            // [i, j), cnts代表[i, j)这个区间里的字符数量
            // 被替换字符的数量 = j - i - [i, j)区间中出现次数最多的字符的数量
            if j - i - maxn > k as usize {
                // 只需要右移动一次
                cnts[s[i] as usize - 'A' as usize] -= 1;
                i += 1;
            }
            // println!("i={} j={} cnts={:?}", i, j, cnts);
        }
        // 可以直接返回最后的j - i
        (j - i) as i32
    }
}

fn main() {
    println!("{}", Solution::character_replacement("ABAB".to_string(), 2));
    println!("{}", Solution::character_replacement("AABABBA".to_string(), 1));
    println!("{}", Solution::character_replacement("BAAAB".to_string(), 2));
    println!("{}", Solution::character_replacement("AAABB".to_string(), 0));
}
