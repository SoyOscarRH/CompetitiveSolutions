#include <iostream>
#include <vector>
#include <map>
#include <array>
#include <algorithm>
using namespace std;

int sockMerchant(int n, vector<int> &socksIDs) {
    vector<int> numberOfSocksOfID(102, 0);
    for (auto& sockID : socksIDs) numberOfSocksOfID[sockID]++;

    for (auto x : socksIDs) cout << x << endl;
    for (auto x : numberOfSocksOfID) if (x) cout << x << endl;


    int pairs = 0;
    for (auto& number : numberOfSocksOfID)
        if (number > 1) pairs += number / 2;

    return pairs;
}
