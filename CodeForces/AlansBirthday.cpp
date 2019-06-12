#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  // No merge cin/cout with scanf/printf
  ios::sync_with_stdio(false);

  // This unties cin from cout
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;

  string word;
  word.reserve(n);
  cin >> word;

  vector<int> numOfTimesLetterAppear(256, 0);
  for (auto letter : word) {
    ++numOfTimesLetterAppear[letter];
  }

  for (char letter = 'a'; letter <= 'z'; ++letter) {
    const int numTimesALetterAppeared = numOfTimesLetterAppear[letter];
    for (int i = 0; i < numTimesALetterAppeared; ++i) {
      cout << letter;
    }
  }

  cout << endl;
  return 0;
}