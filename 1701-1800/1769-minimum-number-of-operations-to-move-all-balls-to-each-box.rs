struct Solution {}

impl Solution {
    pub fn min_operations(boxes: String) -> Vec<i32> {
        let boxes = boxes.bytes().collect::<Vec<_>>();
        let n = boxes.len();
        let mut ans = Vec::<i32>::with_capacity(n);
        let mut cnt = 0;
        for i in 1..n {
            if boxes[i] == b'1' {
                cnt += i as i32;
            }
        }
        ans.push(cnt);
        /*
         * ans[i] = sum((i - j) * boxes[j], j \in [0, i)) + sum((k - i) * boxes[k], k \in [i + 1, n))
         * ans[i - 1] = sum((i - 1 - j) * boxes[j], j \in [0, i - 1)) + sum((k - i + 1) * boxes[k], k \in [i, n))
         * ans[i] - a[i - 1] = sum(boxes[j], j \in [0, i - 1]) - sum(boxes[k], k \in [i, n))
         */
        let tot = boxes.iter().filter(|x| **x == b'1').count() as i32; 
        let mut left = 0;
        for i in 1..n {
            if boxes[i - 1] == b'1' {
                left += 1;
            }
            cnt = cnt + left - (tot - left);
            ans.push(cnt);
        }
        ans
    }
}

fn main() {
    assert_eq!(Solution::min_operations("110".to_string()), vec![1,1,3]);
    assert_eq!(Solution::min_operations("001011".to_string()), vec![11,8,5,4,3,4]);
}
