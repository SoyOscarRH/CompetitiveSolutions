class Solution {
 public:
  auto middleNode(ListNode* const head) -> ListNode* {
    auto *low = head, *fast = head;
    for (auto i = 0; fast; ++i) {
      if (i bitand 1) low = low->next;
      fast = fast->next;
    }

    return low;
  }
};