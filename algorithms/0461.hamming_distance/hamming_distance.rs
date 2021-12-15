impl Solution {
    pub fn hamming_distance(x: i32, y: i32) -> i32 {
        let mut number = x ^ y;
        let mut distance = 0;
        while number > 0 {
            number = number & (number - 1);
            distance += 1;
        }
        distance
    }
}