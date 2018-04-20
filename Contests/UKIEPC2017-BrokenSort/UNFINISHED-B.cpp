#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]) {
	
	//std::ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	vector< pair<int, int> > Points(N);

	for (int i = 0; i < N; ++i) {
		int x, y;
		cin >> x >> y;
		Points[i] = {x, y};
	}

	vector<double> MinimunDistance;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (i == j) continue;
			auto x = 
			sqrt(
						(
							(Points[i].first - Points[j].first)
							*
							(Points[i].first - Points[j].first)
						)
						+ 
						(
							(Points[i].second - Points[j].second)
							*
							(Points[i].second - Points[j].second)
						)
					);
			if (MinimunDistance.size() == 0) MinimunDistance.push_back(x);
			else MinimunDistance[0] = min(MinimunDistance[0],x);

			cout << "Voy con " << x << " con ";
			printf("(%i %i) y (%i %i)\n", Points[i].first,Points[i].second, Points[j].first, Points[j].second);

 		}
	}


	cout << MinimunDistance[0] << "\n";

	return 0;
}