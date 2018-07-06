/*================================================================
=========        CONCIERTO DEL DOCTOR LIRA        ================
==================================================================

*/

#include <iostream>
#include <vector>


std::vector<int> Steps;
int InitialVolume, MaximumVolume;

std::vector< std::vector<int> > MaxPossibleVolumeCalculated;

int MaxPossibleVolume(int CurrentVolume, int Index) {
    
    if (CurrentVolume > MaximumVolume or CurrentVolume < 0) return -1;
    if (Index + 1 > Steps.size()) return CurrentVolume;

    int Previous = MaxPossibleVolumeCalculated[CurrentVolume][Index];
    if (Previous != -2) return Previous;

    int Up = MaxPossibleVolume(CurrentVolume + Steps[Index], Index + 1);
    int Down = MaxPossibleVolume(CurrentVolume - Steps[Index], Index + 1);

    MaxPossibleVolumeCalculated[CurrentVolume][Index] = std::max(Up, Down);
    return MaxPossibleVolumeCalculated[CurrentVolume][Index];
}


int main(int argc, char const *argv[]) {

    using namespace std;
    
    //GET THE DATA
    int NumberOfSteps;
    cin >> NumberOfSteps;
    Steps.resize(NumberOfSteps);

    for (int i = 0; i < NumberOfSteps; ++i) {
        int Temporal;
        cin >> Temporal;
        Steps[i] = Temporal;
    }

    cin >> InitialVolume >> MaximumVolume;

    //CREATE MATRIX FOR THE DP
    MaxPossibleVolumeCalculated.resize(MaximumVolume + 1, vector<int>(NumberOfSteps, -2));

    //CALL IT!
    cout << MaxPossibleVolume(InitialVolume, 0) << "\n";

    return 0;
}









