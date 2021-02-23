struct Solution {}

impl Solution {
    pub fn array_strings_are_equal(word1: Vec<String>, word2: Vec<String>) -> bool {
        word1.iter().fold(String::new(), |acc, x| acc + x) ==
            word2.iter().fold(String::new(), |acc, x| acc + x)
    }
}

fn main() {
    let a = vec!["a", "bc"].iter().map(|x| x.to_string()).collect();
    let b = vec!["ab", "c"].iter().map(|x| x.to_string()).collect();
    assert_eq!(Solution::array_strings_are_equal(a, b), true);
}
