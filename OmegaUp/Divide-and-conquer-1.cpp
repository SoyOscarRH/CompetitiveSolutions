/*================================================================
==========         LARGEST SUM CONTIGOUS SUBARRAY      ===========
================================================================*/

#include <vector>                                                       //Include Libraries
#include <stdio.h>                                                      //Include Libraries
using namespace std;                                                    //Bad practice

inline void getNumber(long long int &Number) {
    
    Number = 0;                                                         //Set to 0
    long long int NumberSign = 1;                                       //Sign all ok
    char CurrentChar = getchar_unlocked();                              //Read a char
 
    while (CurrentChar < '0' or CurrentChar > '9') {                    //If we are not reading numbers
        if (CurrentChar == '-')  NumberSign = -1;                       //If we have found the sign
        CurrentChar = getchar_unlocked();                               //Read the next char
    }

    while (CurrentChar >= '0' and CurrentChar <= '9') {                 //While we read numbers
        Number = (Number << 3) + (Number << 1) + CurrentChar - '0';     //Multiply by 10
        CurrentChar = getchar_unlocked();                               //Read the next char
    }

    Number *= NumberSign;                                               //If negative
}


/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
++++++++++++++++++++        MAIN        ++++++++++++++++++++++++++
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
int main() {
    
    long long int Size;
    getNumber(Size);

    long long int Data[Size];
    for (int i = 0; i < Size; ++i) 
        getNumber(Data[i]);

    long long int MaximumContiguosSum = Data[0];                        //Local vars
    long long int CurrentMaxSum = Data[0];                              //Local vars

    for (int i = 1; i < Size; ++i) {                                    //For each element FROM 1
        if (Data[i] > CurrentMaxSum + Data[i])                          //What is better
            CurrentMaxSum = Data[i];                                    //just take current
        else CurrentMaxSum += Data[i];                                  //or add it to subarray

        if (CurrentMaxSum > MaximumContiguosSum)                        //If we fin new maximum
            MaximumContiguosSum = CurrentMaxSum;                        //Add it!
    }

    printf("%lld\n", MaximumContiguosSum);

    return 0;
}