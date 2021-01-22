struct Solution {}

impl Solution {
    pub fn arrange_coins(n: i32) -> i32 {
        let mut lo: i64 = 0;
        let mut hi: i64 = (n as i64) + 1;
        while lo < hi {
            let mid = lo + ((hi - lo) >> 1) as i64;
            if (1 + mid) * mid / 2 <= (n as i64) {
                lo = mid + 1;
            } else{
                hi = mid;
            }
        }
        (lo - 1) as i32
    }
}

fn main() {
    let n = 5;
    println!("{}", Solution::arrange_coins(n));
}
