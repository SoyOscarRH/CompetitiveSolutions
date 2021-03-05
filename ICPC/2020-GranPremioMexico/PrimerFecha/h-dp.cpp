#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &candiesPerHouse, vector<int> &memory, int index) {
    if(index >= candiesPerHouse.size())
        return 0;
    
    if(memory[index] != 0)
        return memory[index];

    int takeCandies = solve(candiesPerHouse, memory, index + 2) + candiesPerHouse[index];
    int notTakeCandies = solve(candiesPerHouse, memory, index + 1);

    return memory[index] = max(takeCandies, notTakeCandies);
}

int main() {
    int testCases, numberOfHouses;
    vector<int> candiesPerHouse, memory;
    cin >> testCases;

    while(testCases--) {
        cin >> numberOfHouses;
        candiesPerHouse.assign(numberOfHouses, 0);
        memory.assign(numberOfHouses, 0);

        for(int i = 0; i < numberOfHouses; i++)
            cin >> candiesPerHouse[i];

        cout << solve(candiesPerHouse, memory, 0) << endl;
    }
        
    return 0;
}