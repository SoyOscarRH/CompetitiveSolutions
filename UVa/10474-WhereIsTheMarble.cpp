#include <iostream>
#include <vector>
#include <algorithm>

int SemiBinarySearch(std::vector<int>& Data, int left, int right, int item) {
    
    while (left <= right) {
        int point = left + (right -left) / 2;

        if (Data[point] == item) {
            int counter = 0;
            while (point > counter and Data[point - counter - 1] == item) {
                counter++;
            }
            return point - counter;
        }

        if (Data[point] < item) left = point + 1;
        else  right = point - 1;
    }

    return -1;
}

int main () {
    using namespace std;
    
    int NumberOfMarbles, Queries, cases = 1;

    while (true) {
        cin >> NumberOfMarbles >> Queries;
        if (NumberOfMarbles == 0 and Queries == 0) return 0;

        vector<int> Marbles(NumberOfMarbles);
        for(size_t i = 0; i < NumberOfMarbles; i++) cin >> Marbles[i];
        sort(Marbles.begin(), Marbles.end());
        
        cout << "CASE# " << cases++ << ":\n";
        for(int query = 0; query < Queries; query++) {
            int number;
            cin >> number;

            int place = SemiBinarySearch(Marbles, 0, Marbles.size(), number);
            if (place == -1) cout << number << " not found\n";
            else cout << number << " found at " << place + 1 << "\n";
        }
        

    }
    
    return 0;
}
