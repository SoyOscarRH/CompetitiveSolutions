
struct Solution {
  auto deleteNode(ListNode* const node) -> void {
    auto* to_delete = node->next;
    node->val = node->next->val;
    node->next = node->next->next;
    delete to_delete;
  }
};