struct Solution {}

impl Solution {
    pub fn merge_alternately(word1: String, word2: String) -> String {
        let mut ans: String = word1.chars().zip(word2.chars()).map(|(a, b)| vec![a, b]).flatten().collect();
        if word1.len() < word2.len() {
            ans.push_str(&word2[word1.len()..]);
        } else {
            if word1.len() > word2.len() {
                ans.push_str(&word1[word2.len()..]);
            }
        }
        ans
    }
}

fn main() {
    assert_eq!(Solution::merge_alternately("abc".to_string(), "pqr".to_string()), "apbqcr".to_string());
    assert_eq!(Solution::merge_alternately("abc".to_string(), "pqreee".to_string()), "apbqcreee".to_string());
}
