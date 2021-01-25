struct Solution {}

impl Solution {
    pub fn self_dividing_numbers(left: i32, right: i32) -> Vec<i32> {
        (left..=right).filter(|&x| Solution::is_valid(x)).collect()
    }
    fn is_valid(value: i32) -> bool {
        if value == 0 {
            return false;
        }
        let mut v = value;
        while v > 0 {
            let r = v % 10;
            if r == 0 || value % r != 0 {
                return false;
            }
            v /= 10;
        }
        true
    }
}

fn main() {
    let (left, right) = (1, 22);
    println!("{:?}", Solution::self_dividing_numbers(left, right));
}
