struct Solution {}

impl Solution {
    pub fn count_consistent_strings(allowed: String, words: Vec<String>) -> i32 {
        use std::collections::HashSet;
        let se: HashSet<u8> = allowed.bytes().collect();
        let check_fn = |s: &String| {
            for c in s.bytes() {
                if !se.contains(&c) {
                    return false;
                }
            }
            true
        };
        words.iter().filter(|x| check_fn(x)).count() as i32
    }
}

fn main() {
    let allowed = "ab".to_string();
    let words = vec!["ad","bd","aaab","baa","badab"].iter().map(|x| x.to_string()).collect();
    assert_eq!(Solution::count_consistent_strings(allowed, words), 2);
}
