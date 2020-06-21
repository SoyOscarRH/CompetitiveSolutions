struct Solution {
  auto getPermutation(int n, int k) -> string {
    auto permutation_table = array<int, 10> {1};

    for (int i = 1; i <= 9; i++) { permutation_table[i] = i * permutation_table[i - 1]; }

    auto num_set = vector<char> {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

    string result;
    while (n > 0) {
      auto temporal = (k - 1) / permutation_table[n - 1];
      result += num_set[temporal];
      num_set.erase(begin(num_set) + temporal);
      k -= temporal * permutation_table[n - 1];
      n--;
    }

    return result;
  }
};