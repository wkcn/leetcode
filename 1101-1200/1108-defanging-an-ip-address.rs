struct Solution {}

impl Solution {
    pub fn defang_i_paddr(address: String) -> String {
        address.bytes().map(|x| if x == b'.' {"[.]".to_string()} else {(x as char).to_string()}).collect()
    }
}

fn main() {
    assert_eq!(Solution::defang_i_paddr("1.2.3.4".to_string()), "1[.]2[.]3[.]4".to_string());
}
