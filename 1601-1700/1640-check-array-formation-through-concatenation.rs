struct Solution {}

impl Solution {
    pub fn can_form_array(arr: Vec<i32>, pieces: Vec<Vec<i32>>) -> bool {
        // pieces中数字也互不相同
        use std::collections::HashMap;
        let mut ma = HashMap::new();
        pieces.iter().enumerate().for_each(|(i, v)| {ma.insert(v[0], i); });
        let mut i = 0;
        while i < arr.len() {
            if let Some(j) = ma.get(&arr[i]) {
                let ref v = pieces[*j];
                /*
                for k in 0..v.len() {
                    if arr[i] != v[k] {
                        return false;
                    }
                    i += 1;
                }
                */
                // 旧版编译器好像编译不了
                if arr[i..i+v.len()] == *v {
                    i += v.len();
                } else { return false; }
            } else { return false; }
        }
        true
    }
}

fn main() {
    let arr = vec![91,4,64,78];
    let pieces = vec![vec![78],vec![4,64],vec![91]];
    println!("{}", Solution::can_form_array(arr, pieces));
}
