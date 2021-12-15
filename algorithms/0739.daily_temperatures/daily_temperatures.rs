impl Solution {
    pub fn daily_temperatures(temperatures: Vec<i32>) -> Vec<i32> {
        let mut days = vec![0; temperatures.len()];
        
        for i in 0..temperatures.len() {
            for j in i..temperatures.len() {
                if temperatures[j] > temperatures[i] {
                    days[i] = (j - i) as i32;
                    break;
                }
            }
        }
        days
    }
}