#include <vector>
using namespace std;

vector<int> rotLeft(vector<int>& array, int shifts) {
    
    vector<int> leftArray(array.size());
    shifts = shifts % array.size();

    size_t old_i {shifts};
    for (auto& element : leftArray) {
        element = array[old_i % array.size()];
        old_i++;
    }

    return leftArray;
}