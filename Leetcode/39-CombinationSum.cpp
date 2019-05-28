#include <iostream>
#include <vector>

using namespace std;

void sumsTo(vector<vector<int>>& possibleWays, const vector<int>& candidates, const int target, 
            vector<int> partial, const int sum, const int last) {

    if (sum == target) {
        possibleWays.push_back(partial);
        return;
    }
    if (sum >= target) return;

    for (const auto candidate : candidates) {
        if (candidate < last) continue;

        auto newPartial {partial};
        newPartial.push_back(candidate);
        sumsTo(possibleWays, candidates, target, newPartial, sum + candidate, candidate);
    }
}

auto combinationSum(const vector<int>& candidates, const int target) {
    vector<vector<int>> possibleWays {};
    vector<int> sortedCandidates {candidates};
    sort(sortedCandidates.begin(), sortedCandidates.end());

    sumsTo(possibleWays, sortedCandidates, target, vector<int> {}, 0, sortedCandidates[0]);
    return possibleWays;
}