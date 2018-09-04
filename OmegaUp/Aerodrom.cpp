#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int deskTimes[300001];

long optimalTime(long time, int desks) {
	long optimal = 0;
	for (int i = 0; i < desks; i++) optimal += time / deskTimes[i];
	return optimal;
}

int main(int argc, char const *argv[])
{
	long start = 0, end = 0, middle;
	int desks, persons;
	cin >> desks >> persons;

	for (int i = 0, temporal; i < desks; i++) {
		cin >> temporal;
		deskTimes[i] = temporal;
		if(temporal > end) end = temporal;
	}

	end *= persons;

	while (start < end){
		middle = (start + end) / 2;
		if(optimalTime(middle, desks) < persons)
			start = middle + 1;
		else
			end = middle;
	}
	cout << start;
	return 0;
}

