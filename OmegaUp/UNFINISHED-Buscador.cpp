/*================================================================
=======================     BUSCADOR        ======================
==================================================================

READ: https://omegaup.com/arena/problem/Buscador#problems

*/
#include <iostream>
#include <vector>
#include <string>


std::string MostSimilarWord(std::string& Word, std::vector<std::string> &Candidates) {
    using namespace std;
    string Result;
    int Comun = 0;

    for (string Candidate : Candidates) {
        int StartPoint = 0;
        int CurrentComun = 0; 
        for (int i = 0; i < Word.size(); ++i) {
            for (int j = StartPoint; j < Candidate.size(); ++j) {
                if (Word[i] == Candidate[j]) {
                    CurrentComun += 1;
                    StartPoint = j + 1;
                    break;
                }
            }
        }

        if (CurrentComun > Comun) {
            Comun = CurrentComun;
            Result = Candidate;
        }
        else if (CurrentComun == Comun and Result.size() > Candidate.size())
            Result = Candidate;
    }

    return Result;
}



int main(int argc, char const *argv[]) {
    
    using namespace std;

    // GET THE DATA
    int NumberOfCandidates;
    string Word;

    cin >> Word;
    cin >> NumberOfCandidates;

    vector<string> Candidates(NumberOfCandidates);
    for (int i = 0; i < NumberOfCandidates; ++i) {
        string Temporal;
        cin >> Temporal;
        if (Temporal.size() != 0)
            Candidates.push_back(Temporal);
    }


    //CALL THE FUNCTION
    cout << MostSimilarWord(Word, Candidates) << "\n";

    return 0;
}