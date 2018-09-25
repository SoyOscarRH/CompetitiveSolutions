#include <iostream>
#include <vector>

using namespace std;



template <typename T>
T sumEvenValuesOfFibonacciUntil (T limit) { 
    T fibonacci_2 = 0, fibonacci_1 = 1,  fibonacci = 2;
    T sum {};

    while (fibonacci <= limit) {
        fibonacci = fibonacci_2 + fibonacci_1;
        cout << fibonacci;

        if (fibonacci % 2 == 0) {
            cout << " Sum";
            sum += fibonacci;
        }
        cout << "\n";

        fibonacci_2 = fibonacci_1, fibonacci_1 = fibonacci;
    }

    return sum;                         
}



int main () {


    cout << "\n\n" << sumEvenValuesOfFibonacciUntil<uint64_t>(4000000) << endl;
    

    return 0;
}