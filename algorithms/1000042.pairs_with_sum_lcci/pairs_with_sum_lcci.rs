use std::collections::HashMap;
impl Solution {
   
    pub fn pair_sums(nums: Vec<i32>, target: i32) -> Vec<Vec<i32>> {
        let mut tables = HashMap::new();
        let mut result = vec![];
        for &e in nums.iter() {
            let counter = tables.entry(e).or_insert(0);
            *counter += 1;
        }
        for &value in nums.iter() {
            let delta = target - value;
            if tables.contains_key(&delta) && *tables.get(&delta).unwrap() >= 1 && *tables.get(&value).unwrap() >=1 {
                if !(*tables.get(&delta).unwrap() == 1 && delta == value) {
                    let counter = tables.entry(delta).or_insert(0);
                    *counter -= 1;
                    let counter = tables.entry(value).or_insert(0);
                    *counter -= 1;
                    result.push(vec![value, delta]);
                }
            }
        }
        result
    }
}