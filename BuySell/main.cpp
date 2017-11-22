#include <iostream>
#include <vector>
using namespace std;
int BestPrice(vector<int> Prices){
    int Min = Prices[0];
    //Make sure size is big enough
    int MaxProfit = Prices[1] - Prices[0];
    for(int i = 1; i < Prices.size(); i++){
        int Price=Prices[i];
        int CurrentProfit = Price-Min;//Calculate what our currentprofit would be
        MaxProfit = max(MaxProfit, CurrentProfit);
        Min = min(Price, Min);//Calculate if it's our new minimum

    }
    cout << "MaxProfit is: " << MaxProfit << endl;
}
int main()
{
    vector<int> Prices = {5,4,3,2,1};
    BestPrice(Prices);
    cout << "Hello world!" << endl;
    return 0;
}
