/*================================================================
=================     CUENTA ARBOLES        ======================
==================================================================

READ: https://omegaup.com/arena/problem/Buscador#problems

*/
#include <iostream>
#include <vector>
#include <string>


int CountBinaryTree(int Nodes) {
	int UsedNodes = 2;
	int Count = 2;

	while (UsedNodes < Nodes) {
		Count = ((UsedNodes + 1) * Count) -  
		UsedNodes -= 1;
	}
}



int main(int argc, char const *argv[]) {
	
	using namespace std;

	// GET THE DATA
	int NumberOfNodes;
	cin >> NumberOfNodes;

	//CALL THE FUNCTION
	cout << CountBinaryTree(NumberOfNodes) << "\n";

	return 0;
}