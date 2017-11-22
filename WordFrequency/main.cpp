#include <iostream>
#include <unordered_map>
#include <ctype.h>
using namespace std;
unordered_map<string,int> WordFrequencyMap(string InputStream){
    unordered_map<string, int> OutPutMap;
    string word = "";
    for(char a : InputStream){
        if(a == ' '){
            //Add our word to our map
            ++OutPutMap[word];
            cout<<word<<" "<<OutPutMap[word] << endl;
            //Reset our word
            word = "";
        }
        else if(isalpha(a)){
            word+=tolower(a);
        }
    }
    ++OutPutMap[word];
    cout<<word<<" "<<OutPutMap[word] << endl;//Add the last word to the map
    return OutPutMap;
}
int main()
{

    WordFrequencyMap("After beating the eggs, Dana read the next step:");
    return 0;
}
