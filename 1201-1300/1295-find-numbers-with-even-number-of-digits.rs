struct Solution {}

impl Solution {
    pub fn find_numbers(nums: Vec<i32>) -> i32 {
        let f = |mut x: i32| {
            if x == 0 {
                return 1;
            }
            let mut cnt = 0;
            while x != 0 {
                cnt += 1;
                x /= 10;
            }
            cnt
        };
        nums.into_iter().filter(|x| f(*x) % 2 == 0).count() as i32
    }
}

fn main() {
    assert_eq!(Solution::find_numbers(vec![12,345,2,6,7896]), 2);
}
