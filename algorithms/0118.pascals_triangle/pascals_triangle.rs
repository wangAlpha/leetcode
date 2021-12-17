impl Solution {
    fn generate(num_rows: i32) -> Vec<Vec<i32>> {
        let mut n = 1;
        let mut result = vec![vec![1]];
        while n < num_rows {
            let mut line = vec![1];

            for i in 0..(result[n as usize - 1].len() - 1) {
                let r = result[n as usize - 1][i] + result[n as usize - 1][i + 1];
                line.push(r);
            }
            line.push(1);
            result.push(line);
            n += 1;
        }
        result
    }
}