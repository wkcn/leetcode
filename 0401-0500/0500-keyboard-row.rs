struct Solution {}

impl Solution {
    pub fn find_words(words: Vec<String>) -> Vec<String> {
        let mut ans: Vec<String> = Vec::new();
        for s in words.iter() {
            if s.is_empty() {
                continue;
            }
            let ls: Vec<char> = s.to_lowercase().chars().collect();
            if ls.iter().fold(Solution::get_row(ls[0]), |acc, x| {
                    let r = Solution::get_row(*x);
                    if acc == r {acc} else {-1}
                }) != -1 {
                ans.push(s.to_string());
            }
        }
        ans
    }
    fn get_row(c: char) -> i32 {
        match c {
            'q'|'w'|'e'|'r'|'t'|'y'|'u'|'i'|'o'|'p' => 1,
            'a'|'s'|'d'|'f'|'g'|'h'|'j'|'k'|'l' => 2,
            _ => 3,
        }
    }
}

fn main() {
    let words = (vec!["Hello","Alaska","Dad","Peace"]).iter().map(|x| x.to_string()).collect();
    println!("{:?}", Solution::find_words(words));
}
