extern crate rand;

use rand::{thread_rng, Rng};

struct Solution {
    data: Vec<i32>,
    shuffle: Vec<i32>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl Solution {
    fn new(nums: Vec<i32>) -> Self {
        Solution {
            data: nums.clone(),
            shuffle: nums.clone(),
        }
    }

    /** Resets the array to its original configuration and return it. */
    fn reset(&self) -> Vec<i32> {
        self.data.clone()
    }

    /** Returns a random shuffling of the array. */
    fn shuffle(&mut self) -> Vec<i32> {
        for (i, _) in self.data.iter().enumerate() {
            let j: usize = rand::thread_rng().gen_range(0, self.data.len());
            self.shuffle.swap(i as usize, j);
        }
        self.shuffle.clone()
    }
}