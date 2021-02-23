struct Solution {}

impl Solution {
    pub fn decode(encoded: Vec<i32>, first: i32) -> Vec<i32> {
        let mut ans = vec![first];
        let mut v = first;
        for x in encoded {
            v = v ^ x;
            ans.push(v);
        }
        ans
    }
}

fn main() {
    assert_eq!(Solution::decode(vec![1,2,3], 1), vec![1,0,2,1]);
}
