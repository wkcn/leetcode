struct Solution {}

impl Solution {
    pub fn is_one_bit_character(bits: Vec<i32>) -> bool {
        let mut i = 0;
        while i + 1 < bits.len() {
            if bits[i] == 0 {
                i += 1;
            } else {
                i += 2;
            }
        }
        if i + 1 == bits.len() && bits[i] == 0 {
            return true;
        }
        false
    }
}

fn main() {
    let bits = vec![1, 0, 0];
    println!("{}", Solution::is_one_bit_character(bits));

    let bits = vec![1, 1, 1, 0];
    println!("{}", Solution::is_one_bit_character(bits));
}
