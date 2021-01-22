struct Solution {}

impl Solution {
    pub fn reverse_vowels(s: String) -> String {
        if s.is_empty() {
            return s;
        }
        let mut i: usize = 0;
        let mut j: usize = s.len() - 1;
        let mut s: Vec<char> = s.chars().collect();

        while i < j {
            while i < j && !Solution::is_vowel(s[i]) {
                i += 1;
            }
            while i < j && !Solution::is_vowel(s[j]) {
                j -= 1;
            }
            if i < j {
                s.swap(i, j);
                i += 1;
                j -= 1;
            }
        }
        s.iter().collect()
    }
    fn is_vowel(c: char) -> bool {
        match c {
            'a'|'e'|'i'|'o'|'u' => true,
            'A'|'E'|'I'|'O'|'U' => true,
            _ => false,
        }
    }
}

fn main() {
    let a = String::from("leetcode");
    println!("{}", Solution::reverse_vowels(a));
}
