impl Solution {
    pub fn next_greatest_letter(letters: Vec<char>, target: char) -> char {
        let chars: Vec<_> = letters.iter().map(|&c| c as u8).collect();
        let (mut lo, mut hi) = (0, chars.len() as i32 - 1);
        // let (mut lo, mut hi) = (0, chars.len() as i32);
        while lo <= hi {
            let mi = lo + (hi - lo) / 2;
            if letters[mi as usize] <= target {
                lo = mi + 1;
            } else {
                hi = mi - 1;
            }
        }
        if lo < chars.len() as i32 {
            letters[lo as usize]
        } else {
            letters[0]
        }
    }
}