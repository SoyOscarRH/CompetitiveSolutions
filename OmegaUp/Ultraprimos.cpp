#include <iostream>
#include <string>
#include <cmath>
using namespace std;


template <typename T>
bool isPrime(T number) {
    if (number == 1) return true;              // FUCK !!!!!!!!!!!!!!!!!!
    if (number < 2) return false;               
    if (number == 2) return true;               
    if (number % 2 == 0) return false;          

    for (T i = 3; i * i <= number; i += 2)     
        if (number % i == 0) return false;     
    
    return true;                             
}


bool isUltraPrime(string& number) {
    int sumOfDigits {};
    for (auto digit : number) 
        if ('0' <= digit and digit <= '9') sumOfDigits += (digit - '0');

    return isPrime(sumOfDigits);
}

int main() {

    int testCases;
    cin >> testCases;

    while (testCases--) {
        string number;
        cin >> number;
        if (isUltraPrime(number)) cout << "UltraPrimo\n"; 
        else cout << "No UltraPrimo\n";
    }

    return 0;
}

