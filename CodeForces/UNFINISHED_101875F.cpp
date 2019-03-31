
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<iostream>
#include <cstdint>

using namespace std;
using num = uint64_t;
using listNums = vector<num>;

const num LIKE {1}, HATE {2};
const int RESET {-1};

using namespace std;
int main() {
    listNums AllTheHated;

    num numberOfFriends;
    cin >> numberOfFriends;

    unordered_map<num, int> allNumberThatWeTalked;

    // INPUT
    num type {}, numberOfInputs {}, input {};
    num haters {}, lovers {};
    for (num guy = 0; guy < numberOfFriends; ++guy) {
        listNums friendList {};
        cin >> type >> numberOfInputs;
 
        for (num i = 0; i < numberOfInputs; ++i) {
            cin >> input;
            if (type == LIKE) allNumberThatWeTalked[input]++;
            else if (type == HATE) allNumberThatWeTalked[input] = RESET, AllTheHated.push_back(input);
        }

        if (type == LIKE) lovers++;
        else if (type == HATE) haters++;
    }

    if (haters == numberOfFriends) {
        num allPossible {10000000000000000000ull};
        unordered_set<num> reallyHated {};
        for (auto hated : AllTheHated) {
            reallyHated.insert(hated);
        }
        cout << allPossible - reallyHated.size() << endl;
        return 0;
    }

    for (auto hated : AllTheHated) allNumberThatWeTalked[hated] = RESET;
 
    num result {};
    for (auto someNumber : allNumberThatWeTalked) {
        auto numberOfMentions = someNumber.second;
        if (numberOfMentions == lovers) ++result;
    }
 
    cout << result << endl;
    return 0;
}