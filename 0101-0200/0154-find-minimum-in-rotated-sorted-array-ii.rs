struct Solution {
}

impl Solution {
    pub fn find_min(nums: Vec<i32>) -> i32 {
        let (mut lo, mut hi) = (0_usize, nums.len() - 1);
        while lo < hi {
            // if lo < hi, mid < hi
            let mid = lo + (hi - lo) / 2;
            if nums[mid] == nums[hi] {
                hi -= 1;
            } else if nums[mid] < nums[hi] {
                hi = mid;
            } else {
                lo = mid + 1
            }
        }
        nums[lo]
    }
}

fn main() {
    assert_eq!(Solution::find_min(vec![1, 3, 5]), 1);
    assert_eq!(Solution::find_min(vec![2, 2, 2, 0, 1]), 0);
}
