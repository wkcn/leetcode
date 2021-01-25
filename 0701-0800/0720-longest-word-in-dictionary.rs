struct Solution {}

impl Solution {
    pub fn longest_word(words: Vec<String>) -> String {
        use std::collections::HashSet;
        let mut se = HashSet::new(); 
        let mut words = words;
        words.sort_unstable_by(|x, y| x.len().cmp(&y.len()));
        for word in words.iter() {
            if word.len() == 1 || se.contains(&word[..word.len() - 1].to_string()) {
                se.insert(word);
            }
        }
        se.iter().fold(String::new(), |acc, x| {
            if x.len() > acc.len() || (x.len() == acc.len() && x < &&acc) {
                x.to_string()
            } else {acc}
        })
    }
}

fn main() {
    let words: Vec<String> = vec!["a", "banana", "app", "appl", "ap", "apply", "apple"].
                             iter().map(|x| x.to_string()).collect();
    println!("{}", Solution::longest_word(words));
}
