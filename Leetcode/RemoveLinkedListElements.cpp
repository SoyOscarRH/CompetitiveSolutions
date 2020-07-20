struct Solution {
  auto removeElements(ListNode* const head, const int val) -> ListNode* {
    auto* wrapper = new ListNode {0, head};

    for (auto* current = wrapper; current; ) {
      if (current->next and current->next->val == val) current->next = current->next->next;
      else current = current->next;
    }

    return wrapper->next;
  }
};