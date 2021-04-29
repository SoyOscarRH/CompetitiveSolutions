#include <utility>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

struct Solution {
  using node = ListNode;

  auto destroy_repeated(node* current, const int value) -> pair<node*, int> {
    auto destroyed = 0;
    while (current and current->next and current->next->val == value) {
      ++destroyed;
      auto* to_destroy = current;
      current = current->next;
      delete to_destroy;
    }

    return {current->next, destroyed};
  }

  auto get_next_valid_node(node* candidate) -> node* {
    while (candidate) {
      const auto [different_node, destroyed] = destroy_repeated(candidate, candidate->val);
      if (destroyed == 0) { return candidate; }
      candidate = different_node;
    }

    return nullptr;
  }

  auto deleteDuplicates(node* head) -> node* {
    auto fake_head = node {42, head};

    for (auto* current = &fake_head; current; current = current->next) {
      current->next = get_next_valid_node(current->next);
    }

    return fake_head.next;
  }
};