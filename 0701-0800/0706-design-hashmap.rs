struct MyHashMap {
    data: Vec<Vec<(i32, i32)> >,
    md: usize,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MyHashMap {

    /** Initialize your data structure here. */
    fn new() -> Self {
        const MOD: usize = 10007;
        MyHashMap {
            data: vec![vec![]; MOD],
            md: MOD,
        }
    }
    
    /** value will always be non-negative. */
    fn put(&mut self, key: i32, value: i32) {
        let bid = self.get_bucket_id(key);
        for (k, v) in self.data[bid].iter_mut() {
            if *k == key {
                *v = value;
                return;
            }
        }
        self.data[bid].push((key, value));
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    fn get(&self, key: i32) -> i32 {
        let bid = self.get_bucket_id(key);
        for (k, v) in self.data[bid].iter() {
            if *k == key {
                return *v;
            }
        }
        -1
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    fn remove(&mut self, key: i32) {
        let bid = self.get_bucket_id(key);
        self.data[bid].retain(|&x| x.0 != key);
    }

    fn get_bucket_id(&self, key: i32) -> usize {
        key as usize % self.md
    }
}

fn main() {
    let mut ma = MyHashMap::new();
    ma.put(1, 1);
    ma.put(2, 2);
    assert_eq!(ma.get(1), 1);
    assert_eq!(ma.get(3), -1);
    ma.put(2, 1);
    assert_eq!(ma.get(2), 1);
    ma.remove(2);
    assert_eq!(ma.get(2), -1);
}
