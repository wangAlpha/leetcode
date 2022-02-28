impl Solution {
    pub fn matrix_reshape(mat: Vec<Vec<i32>>, r: i32, c: i32) -> Vec<Vec<i32>> {
        if (r * c) as usize == mat.len() * mat[0].len() {
            mat.concat()
                .chunks(c as usize)
                .map(|v| v.to_vec())
                .collect()
        } else {
            mat
        }
    }
}