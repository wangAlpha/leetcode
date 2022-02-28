struct MinStack {
    stack: Vec<i32>,
    min_list: Vec<i32>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MinStack {
    /** initialize your data structure here. */
    fn new() -> Self {
        MinStack {
            stack: vec![],
            min_list: vec![],
        }
    }

    fn push(&mut self, val: i32) {
        if self.stack.is_empty() || self.get_min() > val {
            self.min_list.push(val);
        } else {
            self.min_list.push(self.get_min());
        }
        self.stack.push(val);
    }

    fn pop(&mut self) {
        if !self.stack.is_empty() {
            self.stack.pop();
            self.min_list.pop();
        }
    }

    fn top(&self) -> i32 {
        *self.stack.last().unwrap()
    }

    fn get_min(&self) -> i32 {
        *self.min_list.last().unwrap()
    }
}
