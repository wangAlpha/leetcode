// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
// 
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution {
    pub fn kth_to_last(head: Option<Box<ListNode>>, k: i32) -> i32 {
        let mut cur = head.clone();
        let mut len = 0usize;
        while cur.is_some() {
            cur = cur.unwrap().next;
            len += 1;
        }
        cur = head.clone();
        for _ in 0..len - k as usize {
            cur = cur.unwrap().next;
        }
        cur.unwrap().val
    }
}