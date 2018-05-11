/*================================================================
==========         LARGEST SUM CONTIGOUS SUBARRAY      ===========
================================================================*/
#include <iostream>                                                     //Include Libraries
#include <vector>                                                       //Include Libraries
using namespace std;                                                    //Bad practice




/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
++++++++++++++++++++        MAIN        ++++++++++++++++++++++++++
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
int main() {

    ios_base::sync_with_stdio(0);
    std::ios::sync_with_stdio(0);
    cin.tie(NULL);

    long long int Data[100001];
    long long int Size;

    cin >> Size;

    for (int i = 0; i < Size; ++i) {
        cin >> Data[i];
    }

    long long int MaximumContiguosSum = Data[0];                        
    long long int CurrentMaxSum = Data[0];                              
    for (int i = 1; i < Size; ++i) {                                    

        if (Data[i] > CurrentMaxSum + Data[i])                          
            CurrentMaxSum = Data[i];                                    
        else CurrentMaxSum += Data[i];                                  

        if (CurrentMaxSum > MaximumContiguosSum)                        
            MaximumContiguosSum = CurrentMaxSum;                        
    }

    cout << MaximumContiguosSum << "\n";                                

    return 0;
}