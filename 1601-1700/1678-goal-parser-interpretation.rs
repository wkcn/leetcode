struct Solution {}

impl Solution {
    pub fn interpret(command: String) -> String {
        let mut i: usize = 0;
        let mut ans = String::new();
        let command: Vec<char> = command.chars().collect();
        while i < command.len() {
            match command[i] {
                'G' => {
                    ans += "G";
                    i += 1;
                },
                _ => {
                    if command[i + 1] == ')' {
                        ans += "o";
                        i += 2;
                    } else {
                        ans += "al";
                        i += 4;
                    }
                }
            }
        }
        ans
    }
}

fn main() {
    assert_eq!(Solution::interpret("G()(al)".to_string()), "Goal".to_string());
}
