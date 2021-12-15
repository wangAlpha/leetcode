impl Solution {
    pub fn convert_integer(a: i32, b: i32) -> i32 {
        let mut bits = a ^ b;
        let mut count = 0;
        
        while bits != 0 {
            bits = bits & (bits - 1);
            count +=1 ;
        }
        count
    }
}