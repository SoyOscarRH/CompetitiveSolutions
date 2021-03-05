#include <bits/stdc++.h>
typedef long long lli;

using namespace std;

vector<lli> factorial;

const lli maxNumberOfHamsters = 200001;
const lli MOD = 1000000007;

lli modularInverse(lli a, lli m){
    lli r0 = a, r1 = m, ri, s0 = 1, s1 = 0, si;
    while(r1){
        si = s0 - s1 * (r0 / r1), s0 = s1, s1 = si;
        ri = r0 % r1, r0 = r1, r1 = ri;
    }
    if(r0 < 0) s0 *= -1;
    if(s0 < 0) s0 += m;
    return s0;
}

void calculateFactorialNumbers() {
    factorial.resize(maxNumberOfHamsters + 1);
    factorial[0] = factorial[1] = 1;
    for(int i = 2; i <= maxNumberOfHamsters; i++)
        factorial[i] = (factorial[i - 1] * (i % MOD)) % MOD;
}

inline lli getResult(lli n) {
    //(2n)! / (n - 1)! * m!
    const lli divisor = factorial[2 * n - 1];
    const lli divider = (factorial[n - 1] * factorial[n]) % MOD;
    const lli result = divisor * modularInverse(divider, MOD);
    return result % MOD;
} 

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int numberOfTestCases, numberOfHamsters;
    calculateFactorialNumbers();
    cin >> numberOfTestCases;
    while(numberOfTestCases--) {
        cin >> numberOfHamsters;
        cout << getResult(numberOfHamsters) << endl;
    }
}