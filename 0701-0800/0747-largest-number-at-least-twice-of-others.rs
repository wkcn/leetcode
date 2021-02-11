struct Solution {}

impl Solution {
    pub fn dominant_index(nums: Vec<i32>) -> i32 {
        if nums.is_empty() {
            return -1;
        }
        if nums.len() == 1 {
            return 0;
        }
        let ma_i = nums.iter().enumerate().fold(0_usize, |acc, x| if x.1 > &nums[acc] { x.0 } else {acc});
        let ma = nums[ma_i];
        for (i, x) in nums.into_iter().enumerate() {
            if i != ma_i {
                if x * 2 > ma {
                    return -1;
                }
            }
        }
        ma_i as i32
    }
}

fn main() {
    let nums = vec![0, 1, 1, 2];
    println!("{}", Solution::dominant_index(nums));

    /*
    let nums = vec![3, 6, 1, 0];
    println!("{}", Solution::dominant_index(nums));

    let nums = vec![1, 2, 3, 4];
    println!("{}", Solution::dominant_index(nums));
    */
}
