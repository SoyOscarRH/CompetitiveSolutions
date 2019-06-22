#include <stack>
#include <vector>

using namespace std;

class Solution {
 public:
  void popTheMostWeCan(
    std::stack<int>& theStackWeAreTalkingAbout, 
    std::vector<int>& popped, 
    std::vector<int>::iterator& currentPopped) { 
    while (not theStackWeAreTalkingAbout.empty() 
           and currentPopped != popped.end() 
           and *currentPopped == theStackWeAreTalkingAbout.top()) {
      theStackWeAreTalkingAbout.pop();
      ++currentPopped;
    }
  }
  
  bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    std::stack<int> theStackWeAreTalkingAbout {};
    auto currentPopped {popped.begin()};
    
    for (auto pushedItem : pushed) {
      theStackWeAreTalkingAbout.push(pushedItem);
      popTheMostWeCan(theStackWeAreTalkingAbout, popped, currentPopped);
    }

    popTheMostWeCan(theStackWeAreTalkingAbout, popped, currentPopped);
    
    return theStackWeAreTalkingAbout.empty();
  }
};