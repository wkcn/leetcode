struct MyHashSet {
    table: Vec<Vec<i32>>, // table[key] = [k1, k2]
    md: usize,
}

/*
 * 如何解决key冲突，冲突的key怎么删除
 */
impl MyHashSet {

    /** Initialize your data structure here. */
    fn new() -> Self {
        const MOD: usize = 10007;
        // with_capacity不代表实际的vec大小
        MyHashSet {
            table: vec![vec![]; MOD],
            md: MOD,
        }
    }
    
    fn add(&mut self, key: i32) {
        // key in [0, 10^6]
        let hk = Self::get_hash_key(self, key);
        for k in self.table[hk].iter() {
            if *k == key {
                return;
            }
        }
        self.table[hk].push(key);
    }
    
    fn remove(&mut self, key: i32) {
        let hk = Self::get_hash_key(self, key);
        self.table[hk].retain(|&x| x != key);
    }

    fn get_hash_key(&self, key: i32) -> usize {
        key as usize % self.md
    }
    
    /** Returns true if this set contains the specified element */
    fn contains(&self, key: i32) -> bool {
        let hk = Self::get_hash_key(self, key);
        for k in self.table[hk].iter() {
            if *k == key {
                return true;
            }
        }
        false
    }
}

fn main() {
    let mut se = MyHashSet::new();
    se.add(1);
    se.add(2);
    assert_eq!(se.contains(1), true);
    assert_eq!(se.contains(3), false);
    se.add(2);
    assert_eq!(se.contains(2), true);
    se.remove(2);
    assert_eq!(se.contains(2), false);
}
