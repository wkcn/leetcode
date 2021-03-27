struct Solution2 {}

impl Solution2 {
    pub fn hammingWeight (mut n: u32) -> i32 {
        let mut cnt = 0;
        while n != 0 {
            cnt += 1;
            n &= n - 1;
        }
        cnt
    }
}

struct Solution {}
impl Solution {
    pub fn hammingWeight (mut n: u32) -> i32 {
        n = ((n & 0xaaaaaaaa) >> 1) + (n & 0x55555555); // 1
        n = ((n & 0xcccccccc) >> 2) + (n & 0x33333333); // 2
        n = ((n & 0xf0f0f0f0) >> 4) + (n & 0x0f0f0f0f);
        n = ((n & 0xff00ff00) >> 8) + (n & 0x00ff00ff);
        n = ((n & 0xffff0000) >> 16) + (n & 0x0000ffff);
        n as i32
    }
}

fn main() {
    assert_eq!(Solution::hammingWeight(0b1011), 3);
    assert_eq!(Solution::hammingWeight(0b10000), 1);
    assert_eq!(Solution::hammingWeight(0xFFFFFFFF), 32);
}
