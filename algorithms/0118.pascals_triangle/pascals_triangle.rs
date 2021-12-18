impl Solution {
    fn generate(num_rows: i32) -> Vec<Vec<i32>> {
        let num_rows = num_rows as usize;
        let mut triangle = vec![vec![1]];

        for n in 1..num_rows {
            let last_line = &triangle[n - 1];
            let mut line = vec![1];

            for i in 0..last_line.len() - 1 {
                let sum = last_line[i] + last_line[i + 1];
                line.push(sum);
            }
            line.push(1);
            triangle.push(line);
        }
        triangle
    }
}