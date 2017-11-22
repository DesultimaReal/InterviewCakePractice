#include <iostream>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <sstream>
using namespace std;
class Change2
{
private:
    unordered_map <string, int> Memos;
public:
    int ChangePossibilities(int amount, vector<int>& denominations, size_t current_index = 0){
        cout << current_index;
    }
};
////////////////////////
class Change
{
private:
    unordered_map<string, size_t> memo_;

public:

    size_t changePossibilitiesTopDown(int amountLeft,
            const vector<int>& denominations,
            size_t currentIndex = 0)
    {
        // check our memo and short-circuit if we've already solved this one
        ostringstream oss;
        oss << amountLeft << ", " << currentIndex;
        string memoKey = oss.str();
        auto it = memo_.find(memoKey);
        if (it != memo_.end()) {
            cout << "grabbing memo[" << amountLeft << ", "
                << currentIndex << "]" << endl;
            return it->second;
        }

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

        // save the answer in our memo so we don't compute it again
        memo_.insert(make_pair(memoKey, numPossibilities));
        return numPossibilities;
    }

};

////////////////////////
int main ()
{
    // run your function through some test cases here
    // remember: debugging is half the battle!
    //vector<vector<int>> TestCases = {{1,2,3},{1,2,4},{2,3,4}};
    vector<int> TestCase = {1,2,3};
    Change * temp = new Change;
    cout << temp->changePossibilitiesTopDown(4, TestCase);
    delete temp;
    //return (numberOfWays(5, TestCase));
}
