#[derive(Default)]
struct Trie {
    is_end: bool,
    nodes: [Option<Box<Trie>>; 26], 
}


/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl Trie {

    /** Initialize your data structure here. */
    fn new() -> Self {
        Default::default()
    }
    
    /** Inserts a word into the trie. */
    fn insert(&mut self, word: String) {
        word.chars().fold(self, |cur, c| {
            cur.nodes[c as usize - 'a' as usize].get_or_insert_with(|| Box::new(Trie::new()))
        }).is_end = true;
    }
    
    /** Returns if the word is in the trie. */
    fn search(&self, word: String) -> bool {
        self._find(word).map_or(false, |t| t.is_end)
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    fn starts_with(&self, prefix: String) -> bool {
        self._find(prefix).is_some()
    }

    fn _find(&self, word: String) -> Option<&Trie> {
        let mut cur = self;
        for c in word.chars() {
            match &cur.nodes[c as usize - 'a' as usize] {
                Some(x) => cur = x,
                None => return None, 
            }
        }
        Some(cur)
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * let obj = Trie::new();
 * obj.insert(word);
 * let ret_2: bool = obj.search(word);
 * let ret_3: bool = obj.starts_with(prefix);
 */

fn main() {
    let mut trie = Trie::new();

    trie.insert("apple".to_string());
    assert_eq!(trie.search("apple".to_string()), true);   // 返回 true
    assert_eq!(trie.search("app".to_string()), false);     // 返回 false
    assert_eq!(trie.starts_with("app".to_string()), true); // 返回 true
    trie.insert("app".to_string());
    assert_eq!(trie.search("app".to_string()), true);     // 返回 true
}
