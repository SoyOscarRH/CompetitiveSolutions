#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main(int argc, char const *argv[]) {
	int NumberOfWorlds;
	cin >> NumberOfWorlds;


	vector< vector<int> > Data;
	vector<int> MaxH;
	for (int i = 0; i < NumberOfWorlds; ++i)  {
		int H, R, T;
		cin >> H >> R >> T;

		Data.push_back({H, R, T});
		if (MaxH.size() == 0)
			MaxH.push_back(H);
		else MaxH[0] = (H > MaxH[0])? H : MaxH[0];
	}


	vector<bool> IsNigth(NumberOfWorlds);
	for (int CurrentHour = 0; CurrentHour < MaxH[0] * 1825;) {

		for (int i = 0; i < Data.size(); ++i) {
			int LocalHour = CurrentHour % Data[i][0]; 

			// Dia bonito
			if (Data[i][1] < Data[i][2]){
				if (LocalHour > Data[i][1] and LocalHour < Data[i][2]) {
					IsNigth[i] = false;
					CurrentHour += Data[i][2] - LocalHour;
					break;
				}
				else
					IsNigth[i] = true;
			}
			else {
				if (LocalHour >= Data[i][2] and LocalHour < Data[i][1]) {
					IsNigth[i] = true;
				}
				else {
					IsNigth[i] = false;
					if (LocalHour > Data[i][1]) {
						CurrentHour += (Data[i][2] + Data[i][0]) - LocalHour;
					}
					else 
						CurrentHour += Data[i][2] - LocalHour;
					break;
				}
			}

 		}

		if (std::all_of(IsNigth.begin(), IsNigth.end(), [](bool i){return i;}) ) {
			cout << CurrentHour << "\n";
    		break;
		}

	}

	if (std::all_of(IsNigth.begin(), IsNigth.end(), [](bool i){return i;}) ) 
			return 0;
	else 
    	cout << "impossible\n";

	return 0;
}