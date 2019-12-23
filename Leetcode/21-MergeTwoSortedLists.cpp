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

  auto mergeTwoLists(node* l1, node* l2) -> node* {
    if (not l1 and not l2) return nullptr;

    auto* const head = new node {0};
    auto* current = head;

    while (l1 and l2) {
      const auto a = l1->val, b = l2->val;
      if (a < b) {
        current->next = new node {a};
        l1 = l1->next;
      } else {
        current->next = new node {b};
        l2 = l2->next;
      }
      current = current->next;
    }

    if (l2 and not l1) l1 = l2;

    while (l1) {
      current->next = new node {l1->val};
      current = current->next;
      l1 = l1->next;
    }

    auto* const result = head->next;
    delete head;

    return result;
  }
};