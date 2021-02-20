struct Solution {}

impl Solution {
    pub fn find_shortest_sub_array(nums: Vec<i32>) -> i32 {
        let mut leftest = vec![-1; 50000];
        let mut rightest = vec![-1; 50000];
        let mut cnts = vec![0; 50000];
        for (i, x) in nums.into_iter().enumerate() {
            let x = x as usize;
            if leftest[x] == -1 {
                leftest[x] = i as i32;
            }
            rightest[x] = i as i32;
            cnts[x] += 1;
        }
        let max_cnt = cnts.iter().max().unwrap();
        let mut ans = i32::max_value();
        cnts.iter().enumerate().filter(|x| x.1 == max_cnt).for_each(|x| {
            ans = ans.min(rightest[x.0] - leftest[x.0] + 1);
        });
        ans
    }
}

fn main() {
    assert_eq!(Solution::find_shortest_sub_array(vec![1, 2, 2, 3, 1]), 2);
    assert_eq!(Solution::find_shortest_sub_array(vec![1, 2, 2, 3, 1, 4, 2]), 6);
}
