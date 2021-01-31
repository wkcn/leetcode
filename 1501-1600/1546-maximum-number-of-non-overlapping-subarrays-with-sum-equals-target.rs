struct Solution {}

impl Solution {
    pub fn max_non_overlapping(nums: Vec<i32>, target: i32) -> i32 {
        let mut presum = vec![0]; 
        nums.iter().fold(0, |acc, x| {
            let s = acc + x;
            presum.push(s);
            s
        });
        // 假设当前遍历的值为某个右区间，它是否是最终结果的区间？
        // 肯定是。贪心 + 前缀和
        use std::collections::HashSet;
        let mut se = HashSet::new();
        presum.iter().fold(0, |acc, x| {
            let mut ret = acc;
            if se.contains(&(x - target)) {
                se.clear(); 
                ret += 1;
            }
            se.insert(x);
            ret
        })
    }
}

fn main() {
    let nums = vec![-1,3,5,1,4,2,-9];
    let target = 6;
    println!("{}", Solution::max_non_overlapping(nums, target));

    let nums = vec![-2,6,6,3,5,4,1,2,8];
    let target = 10;
    println!("{}", Solution::max_non_overlapping(nums, target));
}
