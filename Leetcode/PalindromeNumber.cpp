#include <iostream>
using namespace std;

bool isPalindrome(const int number) {
  if (number < 0 or (number % 10 == 0 and number != 0)) return false;

  unsigned long long reverseNumber {};
  int copy {number};

  while (copy > 0) {
    reverseNumber = (10 * reverseNumber) + (copy % 10);
    copy = copy / 10;
  }

  return number == reverseNumber;
}

int maint