struct Solution {}

impl Solution {
    pub fn find_length_of_lcis(nums: Vec<i32>) -> i32 {
        // nums为空时
        if nums.is_empty() {
            return 0;
        }
        // (max_len, cur_len, last_val)
        nums.iter().fold((0, 0, nums[0]), |last_state, &x| {
            let next_len = if x > last_state.2 {
                last_state.1 + 1
            } else {
                1
            };
            // 注意，一开始时max_len = 0, 如果有元素，max_len会等于1
            (last_state.0.max(next_len), next_len, x)
        }).0
    }
}

fn main() {
    let num = vec![1,3,5,4,7];
    println!("{}", Solution::find_length_of_lcis(num));

    let num = vec![2, 2, 2, 2, 2];
    println!("{}", Solution::find_length_of_lcis(num));
}
