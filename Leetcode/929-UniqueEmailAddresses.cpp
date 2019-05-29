#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int numUniqueEmails(const vector<string>& emails) {
  unordered_map<string, int> current {};
  
  for (const auto& email : emails) {
    string name;
    name.reserve(email.size());
    int index = 0;
    bool ignoring {false}, inDomain {false};
    for (char letter : email) {
      if (not inDomain and letter == '+') ignoring = true;
      else if (letter == '@') {
        inDomain = true;
        ignoring = false;
      }
      
      if (ignoring or (letter == '.' and not inDomain)) continue;
      name += letter; 

    }
    current[name]++;
  }

  for (auto x : current) cout << x.first << endl;
  
  return current.size();
}

int main() {
    vector<string> emails {
      "test.email+alex@leetcode.com",
      "test.e.mail+bob.cathy@leetcode.com",
      "testemail+david@lee.tcode.com"
    };

    numUniqueEmails(emails);
}