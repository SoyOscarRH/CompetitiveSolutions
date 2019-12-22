class Solution {
 private:
 public:
  bool isValid(const string& data) {
    auto symbols = map<char, char> {
        {'(', ')'},
        {'{', '}'},
        {'[', ']'},
    };

    auto to_close = stack<char> {};
    for (const auto character : data) {
      const int val = symbols[character];
      if (to_close.size() and character == to_close.top())
        to_close.pop();
      else if (val != 0)
        to_close.push(val);
      else
        return false;
    }

    return not to_close.size();
  }
};