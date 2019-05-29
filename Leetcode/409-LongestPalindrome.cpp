#include <string>
#include <bitset>
using namespace std;

int longestPalindrome(string& data) {
    bitset<256> seen {};
    
    int count {};
    for(char letter : data){
        if (seen[letter]) count++;
        seen.flip(letter);
    }
    
    if (seen.any()) return count * 2 + 1;
    return count * 2;
}