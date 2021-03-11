struct Solution {}
#[derive(Debug, PartialEq)]
enum Token {
    Num(i32),
    Add,
    Sub,
    Mul,
    Div,
    LP,  // 左括号
    RP,  // 右括号
}

impl Token {
    fn get_priority(a: &Token) -> i32 {
        match a {
            Token::Add | Token::Sub => 1,
            Token::Mul | Token::Div => 2,
            _ => -1,
        }
    }
}

struct Calculator;

impl Calculator {
    fn exec_str(s: &str) -> i32 {
        Self::exec(&s.to_string())
    }
    fn exec(s: &String) -> i32 {
        let tokens = Self::get_tokens(s);
        // println!("{:?}", tokens);
        let mut num_st = Vec::new();
        let mut op_st = Vec::new();
        for token in tokens.into_iter() {
            // 如果当前进来的四则运算小于或者等于栈中op的优先级, 则执行栈中的操作
            match token {
                Token::Num(x) => {
                    num_st.push(x);
                }
                Token::Add | Token::Sub | Token::Mul | Token::Div => {
                    while !op_st.is_empty() && Token::get_priority(&token) <= Token::get_priority(op_st.last().unwrap()) {
                        Self::exec_op(&mut num_st, &mut op_st);
                    }
                    op_st.push(token);
                }
                Token::LP => {
                    op_st.push(token);
                }
                Token::RP => {
                    while *op_st.last().unwrap() != Token::LP {
                        Self::exec_op(&mut num_st, &mut op_st);
                    }
                    op_st.pop();  // pop LP
                }
            }
        }
        // 执行剩下的OP
        while !op_st.is_empty() {
            Self::exec_op(&mut num_st, &mut op_st);
        }
        *num_st.last().unwrap_or(&0)
    }
    fn exec_op(num_st: &mut Vec<i32>, op_st: &mut Vec<Token>) {
        let b = num_st.pop().unwrap();
        let a = num_st.pop().unwrap();
        num_st.push(match op_st.pop().unwrap() {
            Token::Add => {
                a + b
            }
            Token::Sub => {
                a - b
            }
            Token::Mul => {
                a * b
            }
            Token::Div => {
                a / b
            }
            _ => {
                println!("Error in exec_op");
                0
            }
        });
    }
    fn get_tokens(s: &String) -> Vec<Token> {
        let s: Vec<_> = s.chars().collect();
        // 正负号只有在：刚 "开始，(, 四则运算符号" 后出现
        let mut begin = true;
        let mut minus = false;
        let mut res = Vec::new();
        let mut i = 0;
        while i < s.len() {
            match s[i] {
                ' ' => {
                }
                '(' => {
                    if minus {
                        // 如果是开头遇到-(
                        res.push(Token::Num(0));
                        res.push(Token::Sub);
                        minus = false;
                    }
                    res.push(Token::LP);
                    begin = true;
                }
                ')' => {
                    res.push(Token::RP);
                    begin = false;
                }
                '+' => {
                    if !begin {
                        res.push(Token::Add);
                        begin = true;
                    }
                }
                '-' => {
                    if !begin {
                        res.push(Token::Sub);
                        begin = true;
                    } else {
                        minus = !minus;
                    }
                }
                '*' => {
                    res.push(Token::Mul);
                    begin = true;
                }
                '/' => {
                    res.push(Token::Div);
                    begin = true;
                }
                c @ '0' ..= '9' => {
                    let mut v = c as i32 - '0' as i32;
                    while i + 1 < s.len() {
                        let c = s[i + 1] as i32 - '0' as i32;
                        if c >= 0 && c <= 9 {
                            i += 1;
                            v = v * 10 + c;
                        } else {
                            break;
                        }
                    }
                    if minus {
                        v = -v;
                    }
                    res.push(Token::Num(v));
                    begin = false;
                    minus = false;
                }
                _ => {
                    println!("Error: {}", i);
                    break;
                }
            }
            i += 1;
        }
        res
    }
}

impl Solution {
    pub fn calculate(s: String) -> i32 {
        Calculator::exec(&s)
    }
}

fn main() {
    assert_eq!(Solution::calculate("1+1".to_string()), 2);
}
