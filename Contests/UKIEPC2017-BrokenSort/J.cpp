#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;


int main (void)
{
	ios_base::sync_with_stdio(0);
	std::ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int> Notes(20);
	long long sum = 0;
	Notes[0] =  32;
	Notes[1] =  16;
	Notes[2] =  8;
	Notes[4] =  4;
	Notes[8] =  2;
	Notes[16] =  1;
	int N = 0, aux = 0;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> aux;
		sum += Notes[aux];
	}

	cout << std::setprecision(6) << (double) sum / 16.0 << "\n";

}