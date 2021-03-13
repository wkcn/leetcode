struct Solution {}

impl Solution {
    pub fn is_valid_serialization(preorder: String) -> bool {
        let s = preorder.bytes().collect::<Vec<u8>>();
        let mut i = 0;
        let mut slots = 1_i32;
        while i < s.len() {
            if slots == 0 {
                return false;
            }
            if s[i] == b'#' {
                // empty node
                slots -= 1;
            } else {
                // num
                slots += 1;
            }
            while i < s.len() && s[i] != b',' {
                i += 1;
            }
            i += 1;
        }
        slots == 0
    }
}

fn main() {
    assert_eq!(Solution::is_valid_serialization("9,3,4,#,#,1,#,#,2,#,6,#,#".to_string()), true);
    assert_eq!(Solution::is_valid_serialization("9,#".to_string()), false);
    assert_eq!(Solution::is_valid_serialization("9,#,#,1".to_string()), false);
    assert_eq!(Solution::is_valid_serialization("#,7,6,9,#,#".to_string()), false);
}
