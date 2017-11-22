#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;
///////////////////////////
  int highestProductOf3(const vector<int>& vectorOfInts)
{
    if (vectorOfInts.size() < 3) {
        throw invalid_argument("Less than 3 items!");
    }

    // we're going to start at the 3rd item (at index 2)
    // so pre-populate highests and lowests based on the first 2 items.
    // we could also start these as null and check below if they're set
    // but this is arguably cleaner
    int highest = max(vectorOfInts[0], vectorOfInts[1]);
    int lowest  = min(vectorOfInts[0], vectorOfInts[1]);

    int highestProductOf2 = vectorOfInts[0] * vectorOfInts[1];
    int lowestProductOf2  = vectorOfInts[0] * vectorOfInts[1];

    // except this one--we pre-populate it for the first *3* items.
    // this means in our first pass it'll check against itself, which is fine.
    int highestProductOf3 = vectorOfInts[0] * vectorOfInts[1] * vectorOfInts[2];

    // walk through items, starting at index 2
    for (size_t i = 2; i < vectorOfInts.size(); ++i) {
        int current = vectorOfInts[i];

        // do we have a new highest product of 3?
        // it's either the current highest,
        // or the current times the highest product of two
        // or the current times the lowest product of two
        highestProductOf3 = max(max(
            highestProductOf3,
            current * highestProductOf2),
            current * lowestProductOf2);

        // do we have a new highest product of two?
        highestProductOf2 = max(max(
            highestProductOf2,
            current * highest),
            current * lowest);

        // do we have a new lowest product of two?
        lowestProductOf2 = min(min(
            lowestProductOf2,
            current * highest),
            current * lowest);

        // do we have a new highest?
        highest = max(highest, current);

        // do we have a new lowest?
        lowest = min(lowest, current);
    }

    return highestProductOf3;
}
///////////////////////////
int highestproductof3(const vector<int>& v){
    //Populate our greedy variables necessary for such a thing
    int highest = max(v[0], v[1]);
    int lowest = min(v[0], v[1]);

    int highestof2 = v[0] * v[1];
    int lowestof2 = v[0] * v[1];

    int highestof3 = v[0] * v[1] * v[2];//Order of population with takesmost -> takesleast



    for(int i = 2; i<v.size();++i){
        int current = v[i];
        highestof3 = max(max(
                    highestof3,
                    highestof2 * current)
                    ,lowestof2 * current);
        highestof2 = max(max(highestof2, current*highest), current*lowest);
        lowestof2 = min(min(lowestof2, current*highest), current*lowest);

        highest=max(highest, current);
        lowest=min(lowest, current);


    cout << endl;
    }


    return highestof3;
}
int main()
{
    vector<int>vectortowatch = {1,-6,3,5,6,-5};

    cout << "Highest of vector via me: " << highestproductof3(vectortowatch) << endl;
    cout << "Highest of vector via them: " << highestProductOf3(vectortowatch) << endl;
    return 0;
}
