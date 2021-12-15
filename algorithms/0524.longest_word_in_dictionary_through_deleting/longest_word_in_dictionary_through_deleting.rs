impl Solution {
    pub fn find_longest_word(s: String, dictionary: Vec<String>) -> String {
        fn find_word(s: &String, word: &String) -> bool {
            let (mut i, mut j) = (0, 0);
            let mut count = 0;
            while i < s.len() && j < word.len() {
                if s.as_bytes()[i] == word.as_bytes()[j] {
                    i += 1;
                    j += 1;
                    count += 1;
                } else {
                    i += 1;
                }
            }
            return count == word.len();
        }

        let mut words = vec![];
        for word in dictionary {
            if find_word(&s, &word) {
                words.push(word.clone());
            }
        }
        if words.is_empty() {
            String::from("")
        } else {
            words.sort_by(|a, b| b.len().cmp(&a.len()).then(Ord::cmp(a, b)));
            words[0].clone()
        }
    }
}