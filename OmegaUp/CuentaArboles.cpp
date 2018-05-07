/*================================================================
=================     CUENTA ARBOLES        ======================
================================================================*/

#include <iostream>
#include <vector>
#include <string>


std::vector<long long int> Memory;

long long int HowManyTrees(long long int Nodes) {
    using namespace std;

    if (Nodes == 1 or Nodes == 0) return 1;
    
    if(Nodes == 2) return 2;
    
    if (Memory[Nodes] == 0) {
        for(long long int i = 1; i <= Nodes; i++ )
            Memory[Nodes] += HowManyTrees(i - 1) * HowManyTrees(Nodes - i);
    }

    return Memory[Nodes] % 1000000;
}

int main() {
    long long int Nodes;
    std::cin >> Nodes;

    Memory.resize(Nodes + 1, 0);

    std::cout << HowManyTrees(Nodes) << "\n";
    
    return 0;
}















