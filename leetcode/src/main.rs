use std::{ascii::AsciiExt, collections::HashMap, hash::Hash, iter::FromIterator};
fn main() {}
type Table<T> = Vec<Vec<T>>;

pub fn diff_ways_to_compute(expression: String) -> Vec<i32> {
    let mut ways = Vec::<i32>::new();
    if expression.is_empty() {
        return ways;
    }
    for i in 0..expression.len() {
        let c = expression.as_bytes()[i] as char;
        if c == '+' || c == '-' || c == '*' {
            let left = diff_ways_to_compute(expression[..i].to_string());
            let right = diff_ways_to_compute(expression[i + 1..].to_string());
            for l in left.iter() {
                for r in right.iter() {
                    match c {
                        '+' => ways.push(l + r),
                        '-' => ways.push(l - r),
                        '*' => ways.push(l * r),
                        _ => (),
                    };
                }
            }
        }
    }
    if ways.is_empty() {
        ways.push(expression.parse().unwrap());
    }
    ways
}

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

pub fn daily_temperatures(temperatures: Vec<i32>) -> Vec<i32> {
    let mut ans = vec![0; temperatures.len()];
    let mut indices = Vec::new();
    for i in 0..temperatures.len() {
        while !indices.is_empty() {
            let pre_index = *indices.last().unwrap();
            if temperatures[i] <= temperatures[pre_index] {
                break;
            }
            ans[pre_index] = (i - pre_index) as i32;
            indices.pop();
        }

        indices.push(i);
    }
    ans
}



mod tests {
    use super::*;
    #[test]
    fn test_next_greater_elements() {
        let elements = vec![1, 2, 1];
        let ans = vec![2, -1, 2];
        assert_eq!(next_greater_elements(elements), ans);

        let elements = vec![1, 2, 3, 4, 3];
        let ans = vec![2, 3, 4, -1, 4];
        assert_eq!(next_greater_elements(elements), ans);

        let elements = vec![1, 2, 3, 4, 5];
        let ans = vec![2, 3, 4, 5, -1];
        assert_eq!(next_greater_elements(elements), ans);

        let elements = vec![1];
        let ans = vec![-1];
        assert_eq!(next_greater_elements(elements), ans);

        let elements = vec![1, 2, 3, 4, 5];
        let ans = vec![2, 3, 4, 5, -1];
        assert_eq!(next_greater_elements(elements), ans);

        let elements = vec![5, 4, 3, 2, 1];
        let ans = vec![-1, 5, 5, 5, 5];
        assert_eq!(next_greater_elements(elements), ans);
    }
    fn test_daily_temperatures() {
        let temperatures = vec![73, 74, 75, 71, 69, 72, 76, 73];
        let output = vec![1, 1, 4, 2, 1, 1, 0, 0];
        assert_eq!(daily_temperatures(temperatures), output);

        let temperatures = vec![30, 40, 50, 60];
        let output = vec![1, 1, 1, 0];
        assert_eq!(daily_temperatures(temperatures), output);

        let temperatures = vec![30, 60, 90];
        let output = vec![1, 1, 0];
        assert_eq!(daily_temperatures(temperatures), output);

        let temperatures = vec![0];
        let output = vec![0];
        assert_eq!(daily_temperatures(temperatures), output);
    }
    fn test_matrix_reshape() {
        let mat = vec![vec![1, 2], vec![3, 4]];
        let output = vec![vec![1, 2, 3, 4]];
        assert_eq!(matrix_reshape(mat, 1, 4), output);

        let mat = vec![vec![1, 2], vec![3, 4]];
        let output = vec![vec![1, 2], vec![3, 4]];
        assert_eq!(matrix_reshape(mat, 2, 4), output);

        // let mat = vec![vec![1, 2], vec![3, 4]];
        let mat = vec![vec![]];
        let output = vec![vec![]];
        assert_eq!(matrix_reshape(mat, 2, 4), output);
        // let mat = [[1,2],[3,4]], r = 2, c = 4
        // Output: [[1,2],[3,4]]
    }
    // #[test]
    fn test_diff_ways_to_compute() {
        let expression = String::from("2-1-1");
        assert_eq!(diff_ways_to_compute(expression), vec![2, 0]);

        let expression = String::from("2*3-4*5");
        assert_eq!(
            unordered_eq(
                &diff_ways_to_compute(expression),
                &vec![-34, -14, -10, -10, 10]
            ),
            true
        );
    }

    fn unordered_eq<T>(a: &[T], b: &[T]) -> bool
    where
        T: Eq + Hash,
    {
        fn count<T>(items: &[T]) -> HashMap<&T, usize>
        where
            T: Eq + Hash,
        {
            let mut cnt = HashMap::new();
            for i in items {
                *cnt.entry(i).or_insert(0) += 1
            }
            cnt
        }

        count(a) == count(b)
    }
}

// [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
