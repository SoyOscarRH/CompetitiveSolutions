#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
long long n,m,k;


int main() {
    cin >> n >> m >> k;
    long long  left = 1, right = n * m;
    
    while (left < right) {
        long long  mid = (left+right) / 2;
        
        long long  ret = 0;
        for (long long i=1; i<=n; i++) ret += min(m,mid/i);
        
        if(ret >= k) right = mid;
        else left = mid+1;
    }

    cout << right << endl;

   return 0;
}
