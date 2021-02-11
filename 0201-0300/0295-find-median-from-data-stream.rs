use std::collections::BinaryHeap;
use std::cmp::Reverse;

#[derive(Default)]
struct MedianFinder {
    left: BinaryHeap<i32>,  // maximum heap
    right: BinaryHeap<Reverse<i32>>,  // minimum heap
}

impl MedianFinder {

    /** initialize your data structure here. */
    fn new() -> Self {
        Default::default()
    }
    
    fn add_num(&mut self, num: i32) {
        self.left.push(num);
        self.right.push(Reverse(self.left.pop().unwrap()));
        if self.right.len() > self.left.len() {
            self.left.push(self.right.pop().unwrap().0);
        }
    }
    
    fn find_median(&self) -> f64 {
        if self.left.len() == self.right.len() {
            return (*self.left.peek().unwrap() as f64 + self.right.peek().unwrap().0 as f64) / 2.0; 
        }
        *self.left.peek().unwrap() as f64
    }
}

fn main() {
    let mut mf = MedianFinder::new();
    mf.add_num(1);
    mf.add_num(2);
    assert_eq!(mf.find_median(), 1.5);
    mf.add_num(3);
    assert_eq!(mf.find_median(), 2.0);
}
