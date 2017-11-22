#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <set>
using namespace std;

  set<string> getPermutations(const string& inputString)
{
    set<string> permutations;

    // base case
    if (inputString.length() <= 1) {
        permutations.insert(inputString);
        return permutations;
    }
    //Seperate the last character and our current string
    string allCharsExceptLast = inputString.substr(0, inputString.length() - 1);
    char lastChar = inputString[inputString.length() - 1];

    // recursive call: get all possible permutations for all chars except last
    set<string> permutationsOfAllCharsExceptLast = getPermutations(allCharsExceptLast);

    // put the last char in all possible positions for each of the above permutations
    for (const string& permutationOfAllCharsExceptLast : permutationsOfAllCharsExceptLast) {
        for (size_t position = 0; position <= allCharsExceptLast.length(); ++position) {
            string permutation = permutationOfAllCharsExceptLast.substr(0, position)
                    + lastChar + permutationOfAllCharsExceptLast.substr(position);
            permutations.insert(permutation);
        }
    }

    return permutations;
}
int main()
{
    string String = "Hello";
    set<string> Permutations =  getPermutations(String);
    for(string S : Permutations){
        cout << S << endl;
    }
    return 0;
}
