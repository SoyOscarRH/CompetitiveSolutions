/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
const mergeTwoLists = (l1, l2) => {
  if (!l1 && !l2) return null;
  let head = new ListNode(-1);
  let current = head;

  while (l1 && l2) {
    const a = l1.val,
      b = l2.val;

    if (a < b) {
      current.next = new ListNode(a);
      l1 = l1.next;
    } else {
      current.next = new ListNode(b);
      l2 = l2.next;
    }

    current = current.next;
  }

  if (l2 && !l1) l1 = l2;

  while (l1) {
    current.next = new ListNode(l1.val);
    current = current.next;
    l1 = l1.next;
  }

  return head.next;
};
