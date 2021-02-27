struct Solution {}

impl Solution {
    pub fn merge(nums1: &mut Vec<i32>, m: i32, nums2: &mut Vec<i32>, n: i32) {
        // 转为i32, 避免0_usize - 1溢出
        let mut i = m - 1;
        let mut j = n - 1;
        let mut k = nums1.len() as i32 - 1;
        while j >= 0 {
            // 注意i < 0的情况
            if i < 0 || nums1[i as usize] <= nums2[j as usize] {
                nums1[k as usize] = nums2[j as usize];
                j -= 1;
            } else {
                nums1[k as usize] = nums1[i as usize];
                i -= 1;
            }
            k -= 1;
        }
    }
}

fn main() {
    let mut nums1 = vec![1,2,3,0,0,0];
    let m = 3;
    let mut nums2 = vec![2, 5, 6];
    let n = 3;
    Solution::merge(&mut nums1, m, &mut nums2, n);
    assert_eq!(nums1, vec![1,2,2,3,5,6]);

    let mut nums1 = vec![0];
    let m = 0;
    let mut nums2 = vec![1];
    let n = 1;
    Solution::merge(&mut nums1, m, &mut nums2, n);
    assert_eq!(nums1, vec![1]);
}
