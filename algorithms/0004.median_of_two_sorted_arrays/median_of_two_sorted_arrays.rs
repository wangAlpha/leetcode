impl Solution {
    pub fn find_median_sorted_arrays(nums1: Vec<i32>, nums2: Vec<i32>) -> f64 {
        if nums1.is_empty() && nums2.is_empty() {
            return 0f64;
        }
        let mut merged_array = vec![0i32; nums1.len() + nums2.len()];
        // merge arrays
        let (mut i, mut j) = (0usize, 0usize);
        let mut index = 0usize;
        while i < nums1.len() || j < nums2.len() {
            if i < nums1.len() && j < nums2.len() {
                if nums1[i] < nums2[j] {
                    merged_array[index] = nums1[i];
                    i += 1;
                } else if j < nums2.len() {
                    merged_array[index] = nums2[j];
                    j += 1;
                }
            } else if i < nums1.len() {
                merged_array[index] = nums1[i];
                i += 1;
            } else if j < nums2.len() {
                merged_array[index] = nums2[j];
                j += 1;
            }
            index += 1;
        }
        // if !nums1.is_empty() && i < nums1.len() - 1 {
        //     while i < nums1.len() {
        //         merged_array[index] = nums1[i];
        //         index += 1;
        //         i += 1;
        //     }
        // }
        // if !nums2.is_empty() && j < nums2.len() - 1 {
        //     while j < nums2.len() {
        //         merged_array[index] = nums2[j];
        //         index += 1;
        //         j += 1;
        //     }
        // }
        if nums1.is_empty() {
            merged_array = nums2;
        } else if nums2.is_empty() {
            merged_array = nums1;
        }

        // println!("{:?}", merged_array);
        if merged_array.len() % 2 == 1 {
            return merged_array[merged_array.len() / 2] as f64;
        } else {
            let i = (merged_array.len() - 1) / 2;
            return (merged_array[i] as f64 + merged_array[i + 1] as f64) / 2f64;
        }
    }
}