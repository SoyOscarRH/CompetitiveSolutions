

/*================================================================
==============     CLOSEST PAIR OF POINTS    =====================
================================================================*/
#include <stdio.h>                                                      //Include Libraries
#include <set>
#include <algorithm> 
#include <vector> 
using namespace std;                                                        //Bad practice

typedef long long int lli;

template<typename T>
struct FenwickTree{
	int N;
	vector<T> bit;

	FenwickTree(int N){
		this->N = N;
		bit.assign(N, 0);
	}

	//single element increment
	void update(int pos, T value){
		while(pos < N){
			bit[pos] += value;
			pos |= pos + 1;
		}
	}

	//range query, [0, r]
	T query(int r){
		T res = 0;
		while(r >= 0){
			res += bit[r];
			r = (r & (r + 1)) - 1;
		}
		return res;
	}

	//range query, [l, r]
	T query(int l, int r){
		return query(r) - query(l - 1);
	}
};


template <class T>  
inline void GetNumber(T &Number) {                                      //Super cool way to read llis
    
    Number = 0;                                                         //Set to 0
    T NumberSign = 1;                                                   //Sign all ok
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




lli CountInversions(lli Data[], lli Size, lli MaxElement) {

	FenwickTree<lli> BIT1(MaxElement + 1);
	FenwickTree<lli> BIT2(MaxElement + 1);
	lli Count = 0;
	for (int i = 0; i < Size; ++i) {
		

	}

	return Count;
}
 


/*========================================
==========        MAIN           =========
========================================*/
int main() {
		
	lli Size;
	GetNumber<lli>(Size);


	lli Data[Size];
	lli MaxElement = 0;
	for (lli j = 0; j < Size; ++j) {
		GetNumber<long long int>(Data[j]);
		MaxElement = max(MaxElement, Data[j]);
	}
	printf("%lld\n", CountInversions(Data, Size, MaxElement));

    return 0;
}