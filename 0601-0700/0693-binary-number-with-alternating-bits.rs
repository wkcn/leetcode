struct Solution2 {}

impl Solution2 {
    pub fn has_alternating_bits(n: i32) -> bool {
        let mut n: u32 = n as u32;
        let mut x = n & 1;
        n >>= 1;
        while n > 0 {
            let y = n & 1;
            if x == y {
                return false;
            }
            x = y;
            n >>= 1;
        }
        true
    }
}

struct Solution {}

impl Solution {
    pub fn has_alternating_bits(n: i32) -> bool {
        let n: u32 = n as u32;
        let v = n ^ (n >> 1);
        // 需要处理高位
        // 有无符号，高位数字，高位异或结果
        // sign, 0, 0
        // sign, 1, 0
        // unsign, 0, 0
        // unsign, 1, 1
        // 注意，并不是看32位
        v & (v + 1) == 0
    }
}

fn main() {
    let a: i32 =  -2_147_483_648;
    println!("{:032b} {:032b}", a, a >> 1);
    let a: u32 =  1 << 31;
    println!("{:032b} {:032b}", a, a >> 1);
    let n = 5;
    println!("{}", Solution::has_alternating_bits(n));
    let n = 3;
    println!("{}", Solution::has_alternating_bits(n));
}
