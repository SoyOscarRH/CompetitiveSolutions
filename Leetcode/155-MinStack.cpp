#import <stack>

template <typename T = int>
class MinStack {
 private:
  stack<int> normal_stack, min_stack;

 public:
  MinStack() : normal_stack {}, min_stack {} {}

  void push(int x) {
    auto const current_min = min_stack.size() ? min_stack.top() : x;
    auto const new_min = std::min(current_min, x);

    min_stack.push(new_min);
    normal_stack.push(x);
  }

  void pop() {
    normal_stack.pop();
    min_stack.pop();
  }

  int top() { return normal_stack.top(); }

  int getMin() { return min_stack.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */