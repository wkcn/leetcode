struct NumArray {
    presum: Vec<i32>
}


/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl NumArray {

    fn new(nums: Vec<i32>) -> Self {
        let mut presum = Vec::with_capacity(nums.len() + 1);
        presum.push(0);
        for x in nums {
            presum.push(presum.last().unwrap() + x);
        }
        NumArray {
            presum: presum,
        }
    }
    
    fn sum_range(&self, i: i32, j: i32) -> i32 {
        // [i, j] = [i, j + 1)
        if j < i {
            return 0;
        }
        self.presum[j as usize + 1] - self.presum[i as usize]
    }
}

fn main() {
    let a = NumArray::new(vec![-2,0,3,-5,2,-1]);
    assert_eq!(a.sum_range(0, 2), 1);
    assert_eq!(a.sum_range(2, 5), -1);
    assert_eq!(a.sum_range(0, 5), -3);
}
