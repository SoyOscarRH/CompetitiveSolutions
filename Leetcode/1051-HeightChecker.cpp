#include <iostream>
#include <vector>

using namespace std;

int heightChecker(const vector<int>& heights) {
    auto correct {heights};
    sort(correct.begin(), correct.end());
    
    int result {};
    for (int i {}; i < heights.size(); ++i) {
        if (heights[i] != correct[i]) result++;
    }
    
    return result;
}