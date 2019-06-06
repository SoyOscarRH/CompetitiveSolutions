#include <vector>
#include <iostream>
#include <cstdint>

using namespace std;
 

int main() {
    // No merge cin/cout with scanf/printf
    ios::sync_with_stdio(false);   

    // This unties cin from cout
    cin.tie(nullptr);
    cout.tie(nullptr);

	int n;
	cin >> n;

	string data;
	data.reserve(n);
	cin >> data;

	vector<int> cubeta(256, 0);
	for (auto letter : data) ++cubeta[letter];
	
	int indexGeneral {-1};
	for (int letter = 'a'; letter <= 'z'; ++letter) {
		for (int i = 0; i < cubeta[letter]; ++i) {
			data[++indexGeneral] = letter;
		}
	}

	cout << data << "\n";
  	return 0;
}