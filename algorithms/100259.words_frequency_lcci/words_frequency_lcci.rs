use std::collections::HashMap;

struct WordsFrequency {
    dict: HashMap<String, usize>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl WordsFrequency {
    fn new(book: Vec<String>) -> Self {
        let mut map = HashMap::new();
        for word in book.iter() {
            let mut entry = map.entry(word.clone()).or_insert(0usize);
            *entry += 1;
        }
        WordsFrequency { dict: map }
    }

    fn get(&self, word: String) -> i32 {
        *self.dict.get(&word).unwrap_or(&0usize) as i32
    }
}
