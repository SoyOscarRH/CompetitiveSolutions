#include <iostream>
#include <string>

using namespace std;

string addStrings(const string& num1, const string& num2) {
  const int maxSize = max(num1.size(), num2.size());
  string result (maxSize, '0');
  const int max1 = num1.size() - 1, max2 = num2.size() - 1, maxIndex = maxSize - 1; 

  int val {}, val1 {}, val2 {}, carry {};
  for (int i1 = max1, i2 = max2, i = maxIndex; i >= 0; --i1, --i2, --i) {
    val1 = (i1 < 0)? 0 : (num1[i1] - '0'); 
    val2 = (i2 < 0)? 0 : (num2[i2] - '0');

    val = val1 + val2 + carry;
    carry = (val >= 10)? 1 : 0;
    result[i] = (val % 10) + '0';
  }

  if (carry != 0) return to_string(carry) + result;
  return result;
}