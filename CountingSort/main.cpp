#include <iostream>
#include <vector>
using namespace std;
/*
Write a function that takes:
a vector of unsortedScores
the highestPossibleScore in the game

and returns a sorted vector of scores in less than O(n\lg{n})O(nlgn) time.
*/
vector<int> CountingSort(vector<int> UnsortedScores, int highestpossiblescore){

vector<int> numEachScore(highestpossiblescore + 1);
vector<int> SortedVector(UnsortedScores.size());
int CurrentSortedIndex = 0;
for(int score : UnsortedScores){ //Takes n time to build a count of each score
    numEachScore[score]++;
}
for(int num = 0; num < numEachScore.size(); num++){
    int Count = numEachScore[num];
    for(int i = 0; i < Count; i++){
        SortedVector[CurrentSortedIndex] = num;
        CurrentSortedIndex++;
    }
}
for(int Score : SortedVector){
    cout << "[" << Score << "]";
}
return SortedVector;

}
int main()
{
    vector<int> scores = {1,3,5,1,2,3,7};
    int highestscore = 10;
    CountingSort(scores, highestscore);
    return 0;
}
