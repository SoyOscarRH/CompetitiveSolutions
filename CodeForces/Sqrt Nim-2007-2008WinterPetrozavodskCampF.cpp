#include <iostream>
#include <set>

using namespace std;

int main () {


    freopen("nim.in", "r", stdin);
    freopen("nim.out", "w", stdout);

    unsigned long long int n;

    cin >> n;

    unsigned long long wrong = 0, jumps = 2;

    set<long long int> wrongs;

    while (wrong <= n) {



        wrong += jumps;

        if(wrong >= jumps*jumps) {
            wrong += 1;
            jumps += 1;
        }

        wrongs.insert(wrong);






    }

    if (wrongs.count(n) != 0)
        cout << "LOSE" << endl;
        else
        cout << "WIN" << endl;


    return 0;
}