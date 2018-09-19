#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
using ull = long long int;

template <typename T>
T getSmallestPrimeFactor(T number) {
    if (number == 1) return 1;
    if (number % 2 == 0) return 2;
    
    for (T i = 3; i * i <= number; i += 2)  
        if (number % i == 0) return i; 
    
    return number;
}

template <typename T>
T WeakenedCommonDivisor(vector< pair<T, T> >& data) {
    
    T possibleResult1 {data[0].first}, possibleResult2 {data[0].second};

    for (const auto& element : data)  {
        possibleResult1 =__gcd(possibleResult1, element.first *element.second);
        possibleResult2 =__gcd(possibleResult2, element.first *element.second);
    }

    if (possibleResult1 != 1) return getSmallestPrimeFactor(possibleResult1);
    if (possibleResult2 != 1) return getSmallestPrimeFactor(possibleResult2);

    return -1;
}

int main () {
    ull elements, a, b;
    cin >> elements;
    vector< pair<ull, ull> > data(elements);

    for(auto& element : data) {
        cin >> a >> b;
        element = {a, b};
    }

    cout << WeakenedCommonDivisor(data) << endl;
}