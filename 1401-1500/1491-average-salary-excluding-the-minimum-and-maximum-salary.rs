struct Solution {}

impl Solution {
    pub fn average(salary: Vec<i32>) -> f64 {
        let (min_v, max_v, su) = salary.iter().fold((salary[0], salary[0], 0_f64), |(min_v, max_v, su), &x| {
            (min_v.min(x), max_v.max(x), su + x as f64)
        });
        (su - (min_v + max_v) as f64) / (salary.len() - 2) as f64
    }
}

fn main() {
    let salary = vec![4000,3000,1000,2000];
    println!("{}", Solution::average(salary));
}
