struct Solution {}

impl Solution {
    pub fn convert_to_base7(num: i32) -> String {
        let mut buf = Vec::new();
        let mut num = num;

        let minus = if num < 0 {
            num = -num;
            true
        } else { false };

        loop {
            buf.push((num % 7).to_string());
            num /= 7;
            if num == 0 {
                break;
            }
        }
        let mut ans : String = "".to_string();
        if minus {
            ans += "-";
        }
        for s in buf.iter().rev() {
            ans += s;
        }
        ans
    }
}

fn main() {
    let num = 100;
    println!("{}", Solution::convert_to_base7(num));
    let num = -7;
    println!("{}", Solution::convert_to_base7(num));
}
