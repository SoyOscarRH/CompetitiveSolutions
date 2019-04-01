#include <iostream> 
#include <fstream> 
#include <unordered_set> 
using namespace std; 
using num = int_fast64_t;

ifstream fin("input.txt");
ofstream fout("output.txt");
  
const num toBigIndex {2 * 10000000};
num A, B, C;

num f(num xi) {return (A * xi + (xi % B)) % C; }

num floyd(num x0) {
    num tortoise = f(x0);
    num hare = f(f(x0));

    //int i {};
    while (tortoise != hare) {
        tortoise = f(tortoise);
        hare = f(f(hare));
        //if (++i > toBigIndex) return -1;
    }
  
    num initialIndex {0};
    for (tortoise = x0; tortoise != hare; ++initialIndex) {
        tortoise = f(tortoise);
        hare = f(hare);
        //if (initialIndex > toBigIndex) return -1;
    }

    num stepsSinceInitial {1};
    for (hare = f(hare); tortoise != hare; ++stepsSinceInitial) {
        hare = f(hare);
        //if (stepsSinceInitial + initialIndex > toBigIndex) return -1;
    }

    return initialIndex + stepsSinceInitial;
}

int main() { 
    fin >> A >> B >> C;
    fout << floyd(1) << endl;
    return 0; 
} 