#include <iostream>
#include <vector>
using namespace std;

  class CakeType
{
public:
    size_t weight_;
    long long value_;

    CakeType(size_t weight = 0, long long value = 0) :
        weight_(weight),
        value_(value)
    {
    }
};
  long long maxDuffelBagValue(const vector<CakeType>& cakeTypes, size_t weightCapacity)
{
    // we make an array to hold the maximum possible value at every
    // duffel bag weight capacity from 0 to weightCapacity
    // starting each index with value 0
    vector<long long> maxValuesAtCapacities(weightCapacity + 1);

    for (size_t currentCapacity = 0; currentCapacity <= weightCapacity; ++currentCapacity) {

        // set a variable to hold the max monetary value so far for currentCapacity
        long long currentMaxValue = 0;

        for (const CakeType& cakeType : cakeTypes) {

            // if the current cake weighs as much or less than the current weight capacity
            // it's possible taking the cake would give get a better value
            if (cakeType.weight_ <= currentCapacity) {

                // so we check: should we use the cake or not?
                // if we use the cake, the most kilograms we can include in addition to the cake
                // we're adding is the current capacity minus the cake's weight. we find the max
                // value at that integer capacity in our array maxValuesAtCapacities
                long long maxValueUsingCake = cakeType.value_
                        + maxValuesAtCapacities[currentCapacity - cakeType.weight_];

                // now we see if it's worth taking the cake. how does the
                // value with the cake compare to the currentMaxValue?
                currentMaxValue = max(maxValueUsingCake, currentMaxValue);
            }
        }

        // add each capacity's max value to our array so we can use them
        // when calculating all the remaining capacities
        maxValuesAtCapacities[currentCapacity] = currentMaxValue;
    }

}

int main()
{
    const vector<CakeType> cakeTypes {
        CakeType(7, 160),
        CakeType(3, 90),
        CakeType(2, 15),
    };
    size_t capacity = 20;

maxDuffelBagValue(cakeTypes, capacity);
// returns 555 (6 of the middle type of cake and 1 of the last type of cake)
    cout << "Hello world!" << endl;
    return 0;
}
