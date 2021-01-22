struct Solution {}

impl Solution {
    pub fn find_nth_digit(n: i32) -> i32 {
        // 1 ～ 9： 9
        // 10 ～ 99： 90
        // 100 ～ 999： 900
        // 1000 ～ 9999： 9000
        let mut w = 1; // 当前位数
        let mut r = 9; // 当前位数的数量
        let mut m = n;  // start at 0
        // r * w会溢出
        while m as i64 > r as i64 * w as i64 {
            m -= r * w;
            w += 1;
            r *= 10;
        }
        // m <= r * w
        // 看看落在当前位数的哪个数字上, 此时m是从1开始数的！
        m -= 1;  // 从0开始数
        let t = r / 9 + m / w; 
        // 100
        // 012
        // 210
        let y: u32 = ((w - 1) - (m % w)) as u32;
        // println!("t = {}, y = {}, r = {}, m = {}, w = {}", t, y, r, m, w);
        (t / 10_i32.pow(y)) % 10
    }
}

fn main() {
    let n = 11;
    println!("{}", Solution::find_nth_digit(n));
    let n = 1;
    println!("{}", Solution::find_nth_digit(n));
    let n = 1000000000;
    println!("{}", Solution::find_nth_digit(n));
} 
