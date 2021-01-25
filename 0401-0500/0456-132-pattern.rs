// TODO: 还有更简单的解法，不需要mins
struct Solution {}

impl Solution {
    pub fn find132pattern(nums: Vec<i32>) -> bool {
        if nums.is_empty() {
            return false;
        }
        let mut mins = Vec::new();
        let mut mi = nums[0];
        for &x in nums.iter() {
            mi = mi.min(x);
            mins.push(mi);
        }
        let mut st = Vec::new();  // 最小栈
        // println!("data: {:?}", nums);
        // println!("mins: {:?}", mins);
        // 注意j开始的位置
        for j in (1..nums.len()).rev() {
            // 下面的条件也可以不加
            if nums[j] > mins[j] {
                while !st.is_empty() && *st.last().unwrap() <= mins[j] {
                    st.pop();
                }
                // 如果st有元素，刚好比mins[j]大
                if !st.is_empty() && *st.last().unwrap() < nums[j] {
                    return true;
                }
                // 栈顶 >= nums[j]
                st.push(nums[j]);
                // println!("st: {:?}", st);
            }
        }
        false
    }
}

fn main() {
    let nums = vec![1, 2, 3, 4];
    assert_eq!(Solution::find132pattern(nums), false);

    let nums = vec![3, 1, 4, 2];
    assert_eq!(Solution::find132pattern(nums), true);

    let nums = vec![3, 5, 0, 3, 4];
    assert_eq!(Solution::find132pattern(nums), true);
    /*
     * nums: 3, 5, 0, 3, 4
     * mins: 3, 3, 0, 0, 0
     */
}
