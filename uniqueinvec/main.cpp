#include <iostream>
#include <vector>
using namespace std;
int findUniqueDeliveryId(const vector<int>& deliveryIds)
{
    int uniqueDeliveryId = 0;

    for (int deliveryId : deliveryIds) {
        uniqueDeliveryId ^= deliveryId;
        //cout << uniqueDeliveryId << endl;
    }

    return uniqueDeliveryId;
}
int main()
{
    vector<int> TwiceWithOneUnique = {1,1,2,3,4,6,3,2,6};
    findUniqueDeliveryId(TwiceWithOneUnique);
    int h = 5;
    h ^= 6;
    cout << h << endl;
    h ^= 6;
    cout << h;
    return 0;
}
