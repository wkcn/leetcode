struct Solution {}

impl Solution {
    pub fn matrix_reshape(nums: Vec<Vec<i32>>, r: i32, c: i32) -> Vec<Vec<i32>> {
        let old_r = nums.len();
        if old_r == 0 {
            return nums;
        }
        let old_c = nums[0].len();
        let r = r as usize;
        let c = c as usize;
        if old_c == 0 || r * c != old_r * old_c {
            return nums;
        }
        nums.into_iter().flatten().collect::<Vec<i32>>().
            chunks(c).map(|x| x.to_vec()).collect()
    }
}

fn main() {
    let nums = vec![vec![1, 2, 3, 4], vec![5, 6, 7, 8], vec![9, 10, 11, 12]];
    println!("{:?}", Solution::matrix_reshape(nums, 2, 6));
}
