#include <iostream>
#include <string>
using namespace std;

int minimumNumber(int n, string& password) {
    bool haveLower{}, haveUpper{}, haveNumber{}, haveSpecial{}; 
    for (auto& character : password) {
        if (character >= '0' and character <= '9') haveNumber= true;
        if (character >= 'a' and character <= 'z') haveLower = true;
        if (character >= 'A' and character <= 'Z') haveUpper = true;
        if (
            character == '!' or character == '@' or character == '#' or
            character == '$' or character == '%' or character == '^' or
            character == '&' or character == '*' or character == '(' or
            character == ')' or character == '-' or character == '+'
        ) haveSpecial = true;
    }

    int moreNecesaryCharacters {0};
    if (!haveLower) moreNecesaryCharacters++;
    if (!haveUpper) moreNecesaryCharacters++;
    if (!haveNumber) moreNecesaryCharacters++;
    if (!haveSpecial) moreNecesaryCharacters++;

    if (moreNecesaryCharacters == 0) {
        if (n >= 6) return 0;
        else return 6 - n;
    }

    if (moreNecesaryCharacters + n <= 6) return  6 - n;

    return moreNecesaryCharacters;
}