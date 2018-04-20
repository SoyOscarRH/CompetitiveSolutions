#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;


int main (void)
{
    ios_base::sync_with_stdio(0);
    std::ios::sync_with_stdio(0);

    int StartR1[3], EndR1[3], OldR1[3];
    int StartR2[3], EndR2[3], OldR2[3];
    cin >> StartR1[0] >> StartR1[1] >> StartR1[2]; 
    cin >> EndR1[0] >> EndR1[1] >> EndR1[2];

    cin >> StartR2[0] >> StartR2[1] >> StartR2[2]; 
    cin >> EndR2[0] >> EndR2[1] >> EndR2[2]; 

    bool MovingR1 = true, MovingR2 = true;
    int AuxXR1, AuxYR1, AuxZR1; 
    int AuxXR2, AuxYR2, AuxZR2; 
    while (MovingR1 or MovingR2) {

        OldR1[0] = StartR1[0];
        OldR1[1] = StartR1[1];
        OldR1[2] = StartR1[2];

        OldR2[0] = StartR2[0];
        OldR2[1] = StartR2[1];
        OldR2[2] = StartR2[2];

        cout << "(" << StartR1[0] << " " << StartR1[1] << " " << StartR1[2] << ") ";
        AuxXR1 = StartR1[0] - EndR1[0];
        if (AuxXR1 != 0) {
            StartR1[0] += (AuxXR1 > 0)? -1 : 1;
        }
        else {
            AuxYR1 = StartR1[1] - EndR1[1];
            if (AuxYR1 != 0) {
                StartR1[1] += (AuxYR1 > 0)? -1 : 1;
            }
            else {
                AuxZR1 = StartR1[2] - EndR1[2];
                if (AuxZR1 != 0) {
                    StartR1[2] += (AuxZR1 > 0)? -1 : 1;
                }
            }
        }
        if (!AuxXR1 and !AuxYR1 and !AuxZR1) MovingR1 = false;

        cout << "(" << StartR2[0] << " " << StartR2[1] << " " << StartR2[2] << ")\n";
        AuxXR2 = StartR2[0] - EndR2[0];
        if (AuxXR2 != 0) {
            StartR2[0] += (AuxXR2 > 0)? -1 : 1;
        }
        else {
            AuxYR2 = StartR2[1] - EndR2[1];
            if (AuxYR2 != 0) {
                StartR2[1] += (AuxYR2 > 0)? -1 : 1;
            }
            else {
                AuxZR2 = StartR2[2] - EndR2[2];
                if (AuxZR2 != 0) {
                    StartR2[2] += (AuxZR2 > 0)? -1 : 1;
                }
            }
        }
        if (!AuxXR2 and !AuxYR2 and !AuxZR2) MovingR2 = false;

        do  {

            if (OldR2[0] == StartR1[0] and OldR2[1] == StartR1[1] and OldR2[1] == StartR1[1]) {
                if (OldR1[0] == StartR1[0]) {
                    StartR1[0] += 1;
                    StartR1[1] = OldR1[1];
                    StartR1[2] = OldR1[2];
                    break;
                }
                if (OldR1[1] == StartR1[1]) {
                    StartR1[1] += 1;
                    StartR1[0] = OldR1[0];
                    StartR1[2] = OldR1[2];
                    break;
                }
                if (OldR1[2] == StartR1[2]) {
                    StartR1[2] += 1;
                    StartR1[0] = OldR1[0];
                    StartR1[1] = OldR1[1];
                    break;
                }
            }
        }
        while (false);


    }

}