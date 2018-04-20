
#include <iostream>
#include <vector>
#include <bitset>

std::vector< std::vector<int> > ReactorsCost;
std::vector<int> Memory;
int NumberOfReactors, ReactorsNecessary;


int MininumCost(int ReactorsActiveAsInt) {
    using namespace std;

    if (Memory[ReactorsActiveAsInt] != -1) return Memory[ReactorsActiveAsInt];

    bitset<16> ReactorsActive(ReactorsActiveAsInt);
    if (ReactorsActive.count() >= ReactorsNecessary) return 0;

    vector<int> Costs;
    for (int i = 0; i < NumberOfReactors; ++i) {
        if (ReactorsActive.test(i) == false) continue;

        for (int j = 0; j < NumberOfReactors; ++j) {
            if (ReactorsActive.test(j)) continue;
            
            bitset<16> NewReactors(ReactorsActive);
            NewReactors[j] = 1;

            if (Costs.size() == 1)
                Costs[0] = min(Costs[0], ReactorsCost[i][j] + MininumCost((int)NewReactors.to_ulong()));
            else Costs.push_back(ReactorsCost[i][j] + MininumCost((int)NewReactors.to_ulong()));
        }
    }

    int BestNewCost = Costs[0];

    Memory[ReactorsActiveAsInt] = BestNewCost;
    return BestNewCost;
}


int main(int argc, char const *argv[]) {
    using namespace std;


    //GET THE DATA
    cin >> NumberOfReactors >> ReactorsNecessary;

    ReactorsCost = vector< vector<int> >
        (NumberOfReactors , vector<int>(NumberOfReactors));

    int Temporal;
    for (int i = 0; i < NumberOfReactors; ++i) {
        for (int j = 0; j < NumberOfReactors; ++j) {
            cin >> Temporal;
            ReactorsCost[i][j] = Temporal;
        }
    }

    Memory = vector<int>(65536 + 1000, -1);

    string ReactorsOn;
    cin >> ReactorsOn;

    bitset<16> ReactorsActive;
    for (int i = 0; i < NumberOfReactors; ++i)
        ReactorsActive[i] = (ReactorsOn[i] == 'Y')? 1: 0;

    cout << MininumCost((int)ReactorsActive.to_ulong()) << "\n";

    return 0;
}