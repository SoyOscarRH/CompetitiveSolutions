#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main(int argc, char const *argv[]) {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int NumberOfWorlds;
    cin >> NumberOfWorlds;

    vector< vector<int> > Data(NumberOfWorlds);
    vector<int> MaxH;
    for (int i = 0; i < NumberOfWorlds; ++i)  {
        int H, R, T;
        cin >> H >> R >> T;

        Data[i] = {H, R, T};

        if (MaxH.size() == 0)
            MaxH.push_back(H);
        else MaxH[0] = (H > MaxH[0])? H : MaxH[0];
    }


    vector<bool> IsNight(NumberOfWorlds);
    int MaxNumberOfHours = 1825 * MaxH[0];

    for (int CurrentHour = 0; CurrentHour < MaxNumberOfHours; ) {

        for (int i = 0; i < Data.size(); ++i) {
            int LocalHour = CurrentHour % Data[i][0]; 

            // Dia bonito
            if (Data[i][1] < Data[i][2]){
                if (LocalHour > Data[i][1] and LocalHour < Data[i][2]) {
                    IsNight[i] = false;
                    CurrentHour += Data[i][2] - LocalHour;
                    break;
                }
                else
                    IsNight[i] = true;
            }
            else {
                if (LocalHour >= Data[i][2] and LocalHour <= Data[i][1]) {
                    IsNight[i] = true;
                }
                else {
                    IsNight[i] = false;
                    if (LocalHour > Data[i][1]) {
                        CurrentHour += (Data[i][2] + Data[i][0]) - LocalHour;
                    }
                    else 
                        CurrentHour += Data[i][2] - LocalHour;
                    break;
                }
            }

        }

        if (std::all_of(IsNight.begin(), IsNight.end(), [](bool i){return i;}) ) {
            cout << CurrentHour << "\n";
            break;
        }

    }

    if (std::all_of(IsNight.begin(), IsNight.end(), [](bool i){return i;}) ) 
            return 0;
    else 
        cout << "impossible\n";

    return 0;
}