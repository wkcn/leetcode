struct Solution {}

impl Solution {
    pub fn search(nums: Vec<i32>, target: i32) -> i32 {
        let (mut lo, mut hi) = (0_usize, nums.len());
        while lo < hi {
            let mid = lo + ((hi - lo) >> 1);
            if nums[mid] < target {
                lo = mid + 1;
            } else { hi = mid; }
        }
        if lo < nums.len() && nums[lo] == target {
            return lo as i32;
        }
        -1
    }
}

fn main() {
    let nums = vec![-1,0,3,5,9,12];
    let target = 9;
    assert_eq!(Solution::search(nums, target), 4);
}
