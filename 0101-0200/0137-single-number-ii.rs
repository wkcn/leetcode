struct Solution {}

/*
impl Solution {
    pub fn single_number(nums: Vec<i32>) -> i32 {
        let mut cnts = vec![0; 32];
        for i in 0..32 {
            let b = (1 as i32) << i;
            for x in nums.iter() {
                if (x & b) != 0 {
                    cnts[i] += 1;
                }
            }
        }
        let mut ans: i32 = 0;
        for i in 0..32 {
            if cnts[i] % 3 == 1 {
                ans |= (1 as i32) << i;
            }
        }
        ans
    }
}
*/

impl Solution {
    pub fn single_number(nums: Vec<i32>) -> i32 {
        let mut b0: i32 = 0;
        let mut b1: i32 = 0;
        // 这里是三进制, 3 = 0b11
        // b1 = b0 = 0
        // b1 ^= b0 & x
        // b0 ^= x
        // mask = ~(b0 & b1)
        // b1 &= mask
        // b0 &= mask
        for x in nums.iter() {
            b1 ^= b0 & x;
            b0 ^= x;
            let mask = !(b0 & b1);
            b1 &= mask;
            b0 &= mask;
        }
        b0
    }
}

fn main() {
    let nums = vec![0, 1, 0, 1, 0, 1, 99, -1, -1, -1];
    println!("{}", Solution::single_number(nums));
}
