use std::collections::HashMap;

impl Solution {
    pub fn find_shortest_sub_array(nums: Vec<i32>) -> i32 {
        let mut nums_degree = HashMap::new();
        for &n in nums.iter() {
            let count = nums_degree.entry(n).or_insert(0);
            *count += 1;
        }

        let degree = *nums_degree.values().max().unwrap();
        let mut degree_pos: HashMap<i32, Vec<usize>> = HashMap::new();
        for i in 0..nums.len() {
            let n = nums[i];
            if nums_degree.contains_key(&n) && nums_degree[&n] == degree {
                let indexs = degree_pos
                    .entry(n)
                    .or_insert(vec![]);
                indexs.push(i);
            }
        }
        degree_pos
            .values()
            .map(|v| v.last().unwrap() - v.first().unwrap())
            .min()
            .unwrap() as i32
            + 1
    }
}