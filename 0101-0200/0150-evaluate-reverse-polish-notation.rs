struct Solution {}

impl Solution {
    pub fn eval_rpn(tokens: Vec<String>) -> i32 {
        if tokens.len() == 0 {
            return 0;
        }
        let mut buf: Vec<i32> = Vec::new();
        for s in tokens {
            if let Ok(v) = s.parse::<i32>() {
                buf.push(v);
            } else {
                let b = buf.pop().unwrap();
                let a = buf.pop().unwrap();
                match s.chars().nth(0).unwrap() {
                    '+' => {
                        buf.push(a + b);
                    }
                    '-' => {
                        buf.push(a - b);
                    }
                    '*' => {
                        buf.push(a * b);
                    }
                    '/' => {
                        buf.push(a / b);
                    }
                    _ => {}
                }
            }
        }
        *buf.last().unwrap()
    }
}

fn my_convert(tokens: Vec<&str>) -> Vec<String> {
    tokens.iter().map(|x| x.to_string()).collect()
}

fn main() {
    assert_eq!(Solution::eval_rpn(my_convert(vec!["4","13","5","/","+"])), 6);
}
