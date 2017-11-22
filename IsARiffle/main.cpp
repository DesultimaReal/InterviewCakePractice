#include <iostream>
#include <vector>
using namespace std;
bool isRiffle(vector<int> ShuffledDeck, vector<int> half1, vector<int> half2){
    if(ShuffledDeck.empty()){
        cout<<"Empty!\n";
        return true;
    }
    int h1Current = 0;
    int h2Current = 0;
    int DeckCurrent = ShuffledDeck[ShuffledDeck.size()-1];
    if(!half1.empty()){
        cout << "hi1\n";
        h1Current = half1[half1.size()-1];
    }
    if(!half2.empty()){
        cout << "hi2\n";
        h2Current = half2[half2.size()-1];
    }

    //cout << "Deck: " << DeckCurrent << "h1: " << h1Current << "h2: " << h2Current << endl;
    if(DeckCurrent == h1Current){
        cout << 1 << endl;
        half1.pop_back();
        ShuffledDeck.pop_back();
    }
    else if(DeckCurrent == h2Current){
        cout << 2 << endl;
        half2.pop_back();
        ShuffledDeck.pop_back();
    }
    else{
        cout << 3 << endl;
        return false;
    }
    isRiffle(ShuffledDeck, half1, half2);
}
int main()
{
    vector<int> half1 = {1,2,3};
    vector<int> half2 = {4,5,6};
    vector<int> ShuffledDeck = {1,4,5,2,6};
    isRiffle(ShuffledDeck,half1,half2)? cout << "Yes" : cout << "No";

    return 0;
}
