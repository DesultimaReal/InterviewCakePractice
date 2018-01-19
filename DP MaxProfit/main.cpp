#include <iostream>
#include <vector>
//Find the maximum profit obtained from buying then selling in an array.
//You cannot sell then buy, and sometimes the best possible profit will be negative as you are still assumed to buy once and sell once.
using namespace std;

int maxProfit(vector<int> p){

    int current;
    int currentmin = p[0];
    int currentprofit = p[1]-p[0];
    int maxprofit = currentprofit;

    for(int i = 1; i < p.size(); i++){
        current = p[i];
        currentprofit = current - currentmin;

        currentmin = min(currentmin, current);
        maxprofit = max(maxprofit, currentprofit);
    }
    return maxprofit;
}

int main()
{
    vector<int> Prices = {4,3,2,1};
    cout<< "Profit P: " << maxProfit(Prices);
    //Max profit is 3 by buying at 1 and selling at 4

    return 0;
}
