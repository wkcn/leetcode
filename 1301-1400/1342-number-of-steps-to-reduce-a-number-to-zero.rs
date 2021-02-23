struct Solution {}

impl Solution {
    pub fn number_of_steps (num: i32) -> i32 {
        let mut ans = 0;
        let mut num = num;
        while num != 0 {
            if num % 2 == 0 {
                num /= 2;
            } else {
                num -= 1;
            }
            ans += 1;
        }
        ans
    }
}

fn main() {
    assert_eq!(Solution::number_of_steps(14), 6);
}
