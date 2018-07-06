/*================================================================
=====        LONGEST INCREASING SUBSEQUENCE          =============
================================================================*/
#include <stdio.h>
#include <stdlib.h>

typedef long long lli;


int main() {        

    int n;
    scanf("%d", &n);

    lli* Data = (lli*) malloc(n * sizeof(lli));

    for (int i = 0; i < n; ++i)
        scanf("%lld", &Data[i]);

    lli* DP = (lli*) malloc(n * sizeof(lli));

    for (int i = 0; i < n; ++i) {
        DP[i] = 1;
    }

    lli maxEl = 1;
    for (lli i = 1; i < n; i++) {                        
        for (lli j = 0; j < i; j++) {                                
            if (Data[i] > Data[j]) {
                if (DP[i] < DP[j] + 1) {
                    DP[i] = DP[j] + 1;

                    if (DP[i] > maxEl) maxEl = DP[i];
                }                       
            }
        }
    }

    printf("%lld\n", maxEl);
    return 0;                                                     
}