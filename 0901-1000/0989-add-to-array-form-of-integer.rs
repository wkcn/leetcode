struct Solution {}

impl Solution {
    pub fn add_to_array_form(a: Vec<i32>, k: i32) -> Vec<i32> {
        let mut st = Vec::new();
        let mut carry = 0;
        let mut k = k;
        for i in (0..a.len()).rev() {
            let v = a[i] + (k % 10) + carry;
            st.push(v % 10); 
            carry = v / 10;
            k /= 10;
        }
        while k > 0 {
            let v = (k % 10) + carry;
            st.push(v % 10); 
            carry = v / 10;
            k /= 10;
        }
        if carry > 0 {
            st.push(carry);
        }
        st.reverse();
        st
    }
}

fn main() {
    let a = vec![1, 2, 0, 0];
    let k = 34;

    println!("{:?}", Solution::add_to_array_form(a, k));
    let a = vec![1, 2, 0, 0];
    let k = 9801;
    println!("{:?}", Solution::add_to_array_form(a, k));
}
