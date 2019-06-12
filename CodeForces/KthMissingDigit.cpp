#include <string>
#include <vector>

#include <algorithm>
#include <cstdint>
#include <iostream>

using namespace std;

int digitSum(const string& number) {
  uint64_t sum {};
  for (char digit : number) sum += (digit - '0');
  if (sum < 10) return sum;

  auto nextStep = to_string(sum);
  return digitSum(nextStep);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  // Read Input
  int _sizeNumberA, _sizeNumberB, _sizeNumberP;
  cin >> _sizeNumberA >> _sizeNumberB >> _sizeNumberP;

  string numberA, numberB, numberP;
  cin >> numberA >> numberB >> numberP;

  // Find the desired digit sum
  int digitSumResult =
      digitSum(to_string(digitSum(numberA) * digitSum(numberB)));

  // Find index of the *
  auto index = find(begin(numberP), end(numberP), '*');
  for (char i {'1'}; i <= '9'; ++i) {
    *index = i;

    if (digitSum(numberP) == digitSumResult) {
      cout << i << endl;
      break;
    }
  }

  return 0;
}