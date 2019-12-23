/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
 public:
  using node = ListNode;
  auto hasCycle(const node* head) -> bool {
    auto *slow = head, *fast = head;
    auto move_slow = false;

    while (slow and fast) {
      fast = fast->next;
      if (move_slow) slow = slow->next;
      move_slow = !move_slow;

      if (slow == fast) return true;
    }

    return false;
  }
};