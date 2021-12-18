impl Solution {
    pub fn daily_temperatures(temperatures: Vec<i32>) -> Vec<i32> {
        let mut ans = vec![0; temperatures.len()];
        let mut indices = Vec::new();
        for i in 0..temperatures.len() {
            while !indices.is_empty() {
                let pre_index = *indices.last().unwrap();
                if temperatures[i] <= temperatures[pre_index] {
                    break;
                }
                ans[pre_index] = (i - pre_index) as i32;
                indices.pop();
            }
            indices.push(i);
        }
        ans
    }
}