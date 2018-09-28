#include <iostream>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int64_t sum(int index, int tupleSize, vector<int>& data, vector<vector<int64_t>>& calculated) {
    if (tupleSize == -1) return 1;               
    if (index == -1) return 0;                       

    if (calculated[index][tupleSize] != -1) return calculated[index][tupleSize]; 

    int64_t ifNthTaken = data[index] * sum(index - 1, tupleSize - 1, data, calculated);
    int64_t ifNthNotTaken = sum(index - 1, tupleSize, data, calculated);
    
    return calculated[index][tupleSize] = (ifNthTaken + ifNthNotTaken) % 1000000007;
}


int main() {
    int n{}, k{3};

    cin >> n;
    vector<int> data(n);
    while(n--) cin >> data[n];

    vector<vector<int64_t>> calculated {data.size(), vector<int64_t>(k,-1)};

    auto ans = sum (data.size() - 1, k - 1, data, calculated);
    cout << ans % 1000000007 << endl;
}
