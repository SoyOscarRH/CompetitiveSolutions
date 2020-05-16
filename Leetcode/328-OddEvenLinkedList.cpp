struct Solution {
  auto next(ListNode*& node) -> void { node = node->next; }
  auto oddEvenList(ListNode* const odd_head) -> ListNode* {
    if (not odd_head or not odd_head->next) return odd_head;

    auto *odd = odd_head, *even = odd_head->next;
    auto* even_head = even;

    auto* current = even->next;
    for (auto i = 0; current; i++, next(current)) {
      auto*& to_edit = (i & 1) ? even : odd;
      to_edit->next = current;
      next(to_edit);
    }

    even->next = nullptr;
    odd->next = even_head;

    return odd_head;
  }
};