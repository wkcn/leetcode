struct Solution {}

impl Solution {
    pub fn find_num_of_valid_words(words: Vec<String>, puzzles: Vec<String>) -> Vec<i32> {
        use std::collections::HashMap;
        let mut cnts = HashMap::new();
        words.iter().map(|s| Self::get_mask(s)).filter(|x| Self::cnt1s(*x) <= 7).for_each(|x| {
            *cnts.entry(x).or_insert(0) += 1;
        });
        /*
         * 10(1)01, first: 00100, mask: 10001
         * v = 10001 -> 10101
         *     10000 -> 10100
         *     00001 -> 00101
         *     00000 -> 00100 (final)
         *     10001 -> break
         */
        puzzles.iter().map(|x| {
            let first = 0_i32 | (1 << (x.bytes().nth(0).unwrap() - b'a'));
            let mask = Self::get_mask(x) & (!first);
            let mut cnt = 0;
            let mut v = mask;
            loop {
                cnt += cnts.get(&(v | first)).unwrap_or_else(|| &0);
                v = (v - 1) & mask;
                if v == mask {
                    break;
                }
            }
            cnt
        }).collect()
    }
    fn get_mask(word: &String) -> i32 {
        word.bytes().fold(0_i32, |acc, x| acc | (1 << (x - b'a')))
    }
    fn cnt1s(mut v: i32) -> i32 {
        let mut cnt = 0;
        while v != 0 {
            v &= v - 1;
            cnt += 1;
        }
        cnt
    }
}

fn to_string(words: Vec<&str>) -> Vec<String> {
    words.iter().map(|x| x.to_string()).collect()
}

fn main() {
    let words = to_string(vec!["aaaa","asas","able","ability","actt","actor","access"]);
    let puzzles = to_string(vec!["aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz"]);
    assert_eq!(Solution::find_num_of_valid_words(words, puzzles), vec![1,1,3,2,4,0]);
}
