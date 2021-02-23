struct Solution {}

impl Solution {
    pub fn max_satisfied(customers: Vec<i32>, grumpy: Vec<i32>, x: i32) -> i32 {
        let x = x as usize;
        let base: i32 = customers.iter().enumerate().filter(|(i, _)| grumpy[*i] == 0).map(|(_, v)| v).sum(); 
        let mut buf: i32 = customers[..x].iter().enumerate().filter(|(i, _)| grumpy[*i] == 1).map(|(_, v)| v).sum();
        let mut other = buf; 
        for i in x..customers.len() {
            if grumpy[i] == 1 {
                buf += customers[i];
            }
            if grumpy[i - x] == 1 {
                buf -= customers[i - x];
            }
            other = other.max(buf);
        }
        base + other
    }
}

fn main() {
    assert_eq!(Solution::max_satisfied(vec![1,0,1,2,1,1,7,5], vec![0,1,0,1,0,1,0,1], 3), 16);
}
