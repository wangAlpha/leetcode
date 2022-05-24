impl Solution {
    pub fn trap(height: Vec<i32>) -> i32 {
        let mut stack = Vec::<usize>::new();
        let mut ans = 0;
        for i in 0..height.len() {
            while !stack.is_empty() && height[*stack.last().unwrap()] < height[i] {
                let cur = *stack.last().unwrap();
                stack.pop();
                if stack.is_empty() {
                    break;
                }
                let left = *stack.last().unwrap();
                let right = i;
                let distance = height[right].min(height[left]) - height[cur];
                ans += distance * (right - left - 1) as i32;
            }
            stack.push(i);
        }
        ans
    }
}