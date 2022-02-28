use std::{collections::HashMap};//, hash::Hash, iter::FromIterator};
impl Solution {
    pub fn intersect(nums1: Vec<i32>, nums2: Vec<i32>) -> Vec<i32> {
        let mut dict = HashMap::new();
        for &n in nums2.iter() {
            let counter = dict.entry(n).or_insert(0);
            *counter += 1;
        }
        let mut result = vec![];
        for &n in nums1.iter() {
            if dict.get(&n) != None {
                result.push(n);
                *dict.get_mut(&n).unwrap() -= 1;
                if dict[&n] <= 0 {
                    dict.remove(&n);
                }
            }
        }
        result
    }
}