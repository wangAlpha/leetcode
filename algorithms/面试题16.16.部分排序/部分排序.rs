impl Solution {
    pub fn sub_sort(array: Vec<i32>) -> Vec<i32> {
        let mut is_sorted = true;
        let mut left_max = 0;
        let mut right_min = array.len();
        for i in 1..array.len() {
            if array[i] < array[i - 1] {
                is_sorted = false;
                break;
            }
            left_max = i;
        }
        for i in (1..array.len()).rev() {
            if array[i] < array[i - 1] || array[i] < array[left_max] {
                right_min = i;
                break;
            }
        }
        if is_sorted || left_max >= right_min {
            return vec![-1, -1];
        }
        let mean_min = *array[left_max..right_min].iter().min().unwrap();
        let mean_max = *array[left_max..right_min].iter().max().unwrap();
        left_max = 0;
        right_min = array.len() - 1;
        while array[left_max] <= mean_min {
            left_max += 1;
        }
        while array[right_min] >= mean_max {
            right_min -= 1;
        }
        vec![left_max as i32, right_min as i32]
    }
}