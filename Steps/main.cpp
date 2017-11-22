#include <iostream>
#include <vector>
using namespace std;
  size_t changePossibilitiesTopDown(int amountLeft,
        const vector<int>& denominations,
        size_t currentIndex = 0)
{

    // base cases:
    // we hit the amount spot on. yes!
    if (amountLeft == 0) {
        return 1;
    }

    // we overshot the amount left (used too many coins)
    if (amountLeft < 0) {
        return 0;
    }

    // we're out of denominations
    if (currentIndex == denominations.size()) {
        return 0;
    }

    cout << "checking ways to make " << amountLeft << " with [";
    for (size_t i = currentIndex; i < denominations.size(); ++i) {
        if (i > currentIndex) {
            cout << ", ";
        }
        cout << denominations[i];
    }
    cout << "]" << endl;

    // choose a current coin
    int currentCoin = denominations[currentIndex];

    // see how many possibilities we can get
    // for each number of times to use currentCoin
    size_t numPossibilities = 0;
    while (amountLeft >= 0) {
        numPossibilities += changePossibilitiesTopDown(amountLeft,
            denominations, currentIndex + 1);
        amountLeft -= currentCoin;
    }

    return numPossibilities;
}

  size_t changePossibilitiesBottomUp(int amount, const vector<int>& denominations)
{
    vector<size_t> waysOfDoingNCents(amount + 1); // vector of zeros from 0..amount
    waysOfDoingNCents[0] = 1;

    for (const int coin : denominations) {
        for (int higherAmount = coin; higherAmount <= amount; ++higherAmount) {
            int higherAmountRemainder = higherAmount - coin;
            waysOfDoingNCents[higherAmount] += waysOfDoingNCents[higherAmountRemainder];
        }
    }

    return waysOfDoingNCents[amount];
}
int main()
{
    vector<int> Coins = {1,3,5};

    cout << changePossibilitiesBottomUp(5, Coins) << endl;
    return 0;
}
