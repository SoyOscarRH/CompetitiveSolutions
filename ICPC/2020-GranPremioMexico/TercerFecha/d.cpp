#include <bits/stdc++.h>

using namespace std;

int main() {
    int testCases, maxSize;
    string str;
    cin >> testCases;
    while(testCases--) {
        cin >> str >> maxSize;
        const int size = str.size();
        int count = 0;
        string num = "";
        vector<pair<long long int, char>> tokens;

        for(char c : str) {
            if(isdigit(c))
                num += c;
            else {
                if(num.size() > 0)
                    tokens.push_back({stoll(num), c}), count += stoll(num);
                else
                    tokens.push_back({1, c}), count++;
                num = "";
            }
        }

        if(count > maxSize) {
            cout << "unfeasible\n";
            continue;
        } else {
            for(const pair<int, char> token : tokens) {
                for(long long int i = 0; i < token.first; i++)
                    cout << token.second;
            }
            cout << "\n";
        }

    }
    return 0;
}