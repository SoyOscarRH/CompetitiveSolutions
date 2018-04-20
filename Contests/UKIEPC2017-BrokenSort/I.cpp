#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main(int argc, char const *argv[])  {
	
	int NumberOfSettings;
	cin >> NumberOfSettings;

	std::vector<int> Settings(NumberOfSettings);

	for (int i = 0; i < NumberOfSettings; ++i) {
		cin >> Settings[i];
	}

	int Tree;
	cin >> Tree;

	vector<int> Min;
	int ActualMin;

	for (int i = 0; i < NumberOfSettings; ++i) {
		int Residue = Tree % Settings[i];
		if (Min.size() == 0) {
			Min.push_back(Residue);
			ActualMin = i;
		}
		else {
			if (Residue < Min[0]){
				Min[0] = Residue;
				ActualMin = i;
			}

		}
	}

	cout << Settings[ActualMin] << "\n";

	return 0;
}