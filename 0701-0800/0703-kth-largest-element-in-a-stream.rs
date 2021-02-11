use std::collections::BinaryHeap;
use std::cmp::Reverse;
struct KthLargest {
    pq: BinaryHeap<Reverse<i32> >,
    k: usize,
}


impl KthLargest {

    fn new(k: i32, nums: Vec<i32>) -> Self {
        let mut pq = BinaryHeap::new();
        for x in nums {
            pq.push(Reverse(x));
        }
        while pq.len() > k as usize {
            pq.pop();
        }
        KthLargest {
            pq: pq,
            k: k as usize,
        }
    }
    
    fn add(&mut self, val: i32) -> i32 {
        self.pq.push(Reverse(val));
        if self.pq.len() > self.k {
            self.pq.pop();
        }
        self.pq.peek().unwrap().0
    }
}

fn main() {
    let mut kl = KthLargest::new(3, vec![4, 5, 8, 2]);
    assert_eq!(kl.add(3), 4);
    assert_eq!(kl.add(5), 5);
    assert_eq!(kl.add(10), 5);
    assert_eq!(kl.add(9), 8);
    assert_eq!(kl.add(4), 8);
}
