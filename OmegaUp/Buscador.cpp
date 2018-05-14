/*================================================================
=====        LONGEST INCREASING SUBSEQUENCE          =============
================================================================*/
#include <iostream>                                                 //Include Libraries
#include <string>                                                   //Include Libraries
#include <vector>                                                   //Include Libraries
using namespace std;                                                //Bad practice


typedef unsigned long long int ull;                                 //Mini name

/*========================================
==========      DP LIS          =========
========================================*/
ull DynamicProgrammingLIS (string &A, string &B) {                  //Cool LIS

    ull Table [A.size() + 1][B.size() + 1];                         //Table

    for (int i = 0; i < A.size() +1; ++i) {
        for (int j = 0; j < B.size() +1; ++j)
            Table[i][j] = 0;
    }

    for (int i = 1; i < A.size() + 1; ++i) {                        //For each char
        for (int j = 1; j < B.size() + 1; ++j) {                    //For each char
            if (A[i] == B[j])                                       //If equals, add it
                Table[i][j] = 1 + Table[i-1][j-1];                  //Move the 2 pointers
            else                                                    //if not equals
                Table[i][j] = max(Table[i-1][j], Table[i][j-1]);    //Move the max of the 2
        }
    }

    return Table[A.size()][B.size()];                               //Return the bigger
}



int main() {

    string Name;
    cin >> Name;

    ull NumWords;
    cin >> NumWords;

    vector<string> Words(NumWords);

    for (ull i = 0; i < NumWords; ++i)
        cin >> Words[i];

    vector<ull> Price(NumWords);

    for (ull i = 0; i < NumWords; ++i) {
        Price[i] = DynamicProgrammingLIS(Name, Words[i]);
    }

    ull Max = Price[0];
    ull Position = 0;
    for (int i = 1; i < NumWords; ++i) {
        if (Price[i] > Max or (Price[i] == Max and Words[i].size() < Words[Position].size())) {
            Max = Price[i];
            Position = i;
        }
    }  

    cout << Words[Position] << "\n";                    //Try DP LSI 

    return 0;
}