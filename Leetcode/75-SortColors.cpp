struct Solution {
  auto sortColors(vector<int>& nums) -> void {
    int second = nums.size() - 1, zero = 0;
    for (auto i = 0; i <= second; ++i) {
      while (A[i] == 2 and i < second) swap(A[i], A[second--]);
      while (A[i] == 0 and i > zero) swap(A[i], A[zero++]);
    }
  }
};