impl Solution {
    pub fn frequency_sort(s: String) -> String {
        let mut chars: Vec<char> = s.chars().collect();
        let mut dict = [0u16; 128];
        let index = |ch| ch as usize - 30;
        for ch in s.chars() {
            dict[index(ch)] += 1;
        }
        chars.sort_by(|&a, &b| {
            if dict[index(b)] == dict[index(a)] {
                index(b).cmp(&index(a))
            } else {
                dict[index(b)].cmp(&dict[index(a)])
            }
        });
        // println!("{:?}", chars);
        chars.into_iter().collect()
    }
}