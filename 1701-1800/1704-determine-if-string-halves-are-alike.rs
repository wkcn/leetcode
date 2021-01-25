struct Solution {}

impl Solution {
    pub fn halves_are_alike(s: String) -> bool {
        let len = s.len();
        let half = len / 2;
        let left = s[..half].chars().fold(0_i32, |acc, x| acc + Solution::is_vowel(x) as i32);
        /*
        let mut acc = 0_i32;
        for x in s[..half].chars() {
            acc = acc + Solution::is_vowel(x) as i32;
        }
        */
        let right = s[half..].chars().fold(0_i32, |acc, x| acc + Solution::is_vowel(x) as i32);
        left == right
    }
    fn is_vowel(x: char) -> bool {
        match x {
            'a' | 'e' | 'i' | 'o' | 'u' => true,
            'A' | 'E' | 'I' | 'O' | 'U' => true,
            _ => false,
        }
    }
}

fn main() {
    let s = "book".to_string();
    println!("{}", Solution::halves_are_alike(s));
}
