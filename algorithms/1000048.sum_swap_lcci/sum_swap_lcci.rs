use std::collections::HashSet;

impl Solution {
    pub fn find_swap_values(array1: Vec<i32>, array2: Vec<i32>) -> Vec<i32> {
        let delta: i32 = array1.iter().sum::<i32>() - array2.iter().sum::<i32>();
        let mut result = Vec::<i32>::new();
        let table: HashSet<&i32> = array2.iter().collect();
        if delta % 2 == 0 {
            let delta = delta / 2;
            for &value in array1.iter() {
                let need_val = value - delta;
                if table.contains(&need_val) {
                    result = vec![value, need_val];
                    break;
                }
            }
        }
        result
    }
}