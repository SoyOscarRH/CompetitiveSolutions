// Optimized C++ program to find sequences of all consecutive
// numbers with sum equal to N
#include <stdio.h>

void printSums(int N) {
  int start = 1, end = 1;
  int sum = 1;

  while (start <= N / 2) {
    if (sum < N) {
      end += 1;
      sum += end;
    } else if (sum > N) {
      sum -= start;
      start += 1;
    } else if (sum == N) {
      for (int i = start; i <= end; ++i) printf("%d ", i);

      printf("\n");
      sum -= start;
      start += 1;
    }
  }
}

// Driver Code
int main() {
  printSums();
  return 0;
}