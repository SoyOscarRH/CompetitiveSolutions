
class MinStack {
  struct node {
    int val;
    node* next;
    node(int val, node* next = nullptr) : val {val}, next {next} {}
  };

 private:
  node* min_val;
  node* head;

 public:
  /** initialize your data structure here. */
  MinStack() : head {nullptr}, min_val {nullptr} {}

  void push(int x) {
    auto* new_head = new node(x, head);
    if (!min_val)
      min_val = new node(x, nullptr);
    else if (x <= min_val->val)
      min_val = new node(x, min_val);
    head = new_head;
  }

  void pop() {
    if (!head) return;
    if (min_val->val == head->val) min_val = min_val->next;
    head = head->next;
  }

  int top() const { return head->val; }

  int getMin() { return min_val->val; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */