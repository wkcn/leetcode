struct Solution {}

impl Solution {
    pub fn partition(s: String) -> Vec<Vec<String>> {
        let n = s.len();
        let mut isp = vec![vec![-1; n]; n];  // s[i, j]是回文字
        let mut buf = Vec::new();
        let mut ans = Vec::new();
        Self::dfs(0, &s, &mut isp, &mut buf, &mut ans);
        ans
    }
    fn dfs(i: usize, s: &String, isp: &mut Vec<Vec<i32>>, buf: &mut Vec<String>, ans: &mut Vec<Vec<String>>) {
        let n = s.len();
        if i >= n {
            ans.push(buf.to_vec());
        }
        for j in i..n {
            if Self::is_palindrome(s, isp, i, j) {
                buf.push(s[i..=j].to_string());
                Self::dfs(j + 1, s, isp, buf, ans);
                buf.pop();
            }
        }
    }
    fn is_palindrome(s: &String, isp: &mut Vec<Vec<i32>>, i: usize, j: usize) -> bool {
        if isp[i][j] != -1 {
            return isp[i][j] != 0;
        }
        if i >= j {
            isp[i][j] = 1;
            return true;
        }
        let b = s[i..=i] == s[j..=j] && Self::is_palindrome(s, isp, i + 1, j - 1); 
        isp[i][j] = b as i32;
        b
    }
}

fn main() {
    println!("{:?}", Solution::partition("aab".to_string()));
}
