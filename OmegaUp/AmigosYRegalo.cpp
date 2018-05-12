/*================================================================
==========                AMIGOS Y REGALOS             ===========
==================================================================

https://omegaup.com/arena/problem/Divide-and-conquer-1#problems */

#include <iostream>                                                     //Include Libraries
#include <vector>                                                       //Include Libraries
using namespace std;                                                    //Bad practice

typedef unsigned long long ull;                                         //Just a so long name, sorry
typedef long long lli;                                             		//Just a so long name, sorry



void BinarySearch(ull MaxLimit) {
	if (MaxLimit < 1) return;
	
	ull ValidNumbers

	long long int i = 1;
	for (; NumberOfInts1 > 0 or NumberOfInts2 > 0 ; ++i) {
		if (i % Prime1 != 0) NumberOfInts1--; 
		else if (i % Prime2 != 0) NumberOfInts2--;
	}
	


	cout << MaxLimit << "\n";
	BinarySearch(MaxLimit / 2);
}


int main() {

	lli NumberOfInts1, NumberOfInts2, Prime1, Prime2;

	cin >> NumberOfInts1 >> NumberOfInts2 >> Prime1 >> Prime2;

	ull x = -1;

	BinarySearch(x);


	return 0;
}

