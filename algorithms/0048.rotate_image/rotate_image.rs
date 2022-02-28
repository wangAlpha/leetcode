impl Solution {
     pub fn rotate(matrix: &mut Vec<Vec<i32>>) {
        // 先镜像交换
        let len = matrix.len();

        for i in 0..len {
            for j in i + 1..len {
                unsafe {
                    let a: *mut i32 = &mut matrix[i][j];
                    let b: *mut i32 = &mut matrix[j][i];
                    std::ptr::swap(a, b);
                }
            }
        }
        // 再镜像交换
        for i in 0..len {
            for j in 0..len / 2 {
                matrix[i].swap(j, len - j - 1);
            }
        }
    }
}