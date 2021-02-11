struct Solution {}

impl Solution {
    pub fn check_possibility(nums: Vec<i32>) -> bool {
        /*
         * if a > b,
         * 减小a或者增大b
         * 优先减小a
         * 记a前面的数是c, 有c <= a
         * 如果c <= b, 可以减小a, b不变
         * 否则b = a
         */
         if nums.is_empty() {
             return true;
         }
         let mut i = 0;
         let mut last = nums[0];
         while i < nums.len() - 1 {
             if nums[i] > nums[i + 1] {
                 // 发现逆序对
                 if i == 0 || nums[i - 1] <= nums[i + 1] {
                     // 更改a
                     last = nums[i + 1];
                     break;
                 } else {
                     // 更改b
                     last = nums[i];
                     break;
                 }
             }
             i += 1;
         }
         for j in (i + 2)..nums.len() {
             if nums[j] < last {
                 return false;
             }
             last = nums[j];
         }
         true
    }
}

fn main() {
    let nums = vec![4, 2, 3];
    println!("{}", Solution::check_possibility(nums));
    let nums = vec![4, 2, 1];
    println!("{}", Solution::check_possibility(nums));
}
