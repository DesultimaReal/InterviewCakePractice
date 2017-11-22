#include <iostream>
#include <vector>
#include <limits>
using namespace std;
/*
Write a class TempTracker with these methods:
insert()—records a new temperature
getMax()—returns the highest temp we've seen so far
getMin()—returns the lowest temp we've seen so far
getMean()—returns the mean ↴ of all temps we've seen so far//Avg
getMode()—returns a mode ↴ of all temps we've seen so far//We have the most of
Optimize for space and time. Favor speeding up the getter methods getMax(), getMin(), getMean(), and getMode() over speeding up the insert() method.
getMean() should return a double, but the rest of the getter methods can return integers.
Temperatures will all be inserted as integers. We'll record our temperatures in Fahrenheit, so we can assume they'll all be in the range 0..1100..110.
If there is more than one mode, return any of the modes.
*/

class TempTracker{
private:
    //For Mode
    vector<int>Occurences;
    int MaxOccurences;
    int Mode;
    //For Min and Max
    int MinTemp;
    int MaxTemp;
    //For mean
    int NumValues;
    double Avg;
    int Sum;
public:
    TempTracker():
        MinTemp(numeric_limits<int>::max()),
        MaxTemp(numeric_limits<int>::min()),
        NumValues(0),Avg(0.0),Sum(0), MaxOccurences(0), Occurences(111), Mode(0)
        {

        }
    void insertT(int temperature){
        //For Mode
        int CurrentOcc = Occurences[temperature]++;
        if(CurrentOcc > MaxOccurences){
            MaxOccurences = CurrentOcc;
            Mode = temperature;
        }
        //For Min/Max
        MinTemp = min(MinTemp, temperature);
        MaxTemp = max(MaxTemp, temperature);

        NumValues++;
        Sum+=temperature;
        Avg=(Sum)/(NumValues);
        //cout << "After inserting " << temperature << " new Avg is " << Avg << endl;

    }
    getMin(){
        return MinTemp;
    }
    getMax(){
        return MaxTemp;
    }
    getMean(){
        return Avg;
    }
    getMode(){
        return Mode;
    }
};

int main()
{
    TempTracker * temp = new TempTracker();
    temp->insertT(5);
    temp->insertT(4);
    //temp->insertT(1);
    cout << temp->getMode();
    delete temp;

    return 0;
}
