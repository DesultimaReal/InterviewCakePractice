#include <iostream>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <sstream>
using namespace std;
//What I learned... you can set defaults at the end of the parameters to use if those parameters are missing in the call
//
class Change
{
private:
    unordered_map <string, int> Memos;
public:
    int ChangePossibilities(int amountleft, vector<int>& denominations, size_t current_index = 0){
        // check our memo and short-circuit if we've already solved this one
        ostringstream oss;
        oss << amountleft << ", " << current_index;
        string KeyForAmount = oss.str();
        auto it = Memos.find(KeyForAmount);
        if(it != Memos.end()){//If we can find it in memos
            cout << "Using memo: " << KeyForAmount << endl;
            return it->second;
        }


        if(amountleft == 0){//We are right on the money and can finally return a path
            return 1;
        }
        if(amountleft < 0){//We overshot, thus this isnt a viable way to make the amount
            return 0;
        }
        if(current_index == denominations.size()){//We are at the end of our vector
            return 0;
        }
        cout << "checking ways to make " << amountleft << " with [";
        for (size_t i = current_index; i < denominations.size(); ++i) {
            if (i > current_index) {
                cout << ", ";
            }
            cout << denominations[i];
        }
        cout << "]" << endl;

        int numPossibilities = 0;
        int currentcoin = denominations[current_index];
        while(amountleft >= 0){
            numPossibilities+=ChangePossibilities(amountleft, denominations, current_index+1);
            amountleft -= currentcoin;
        }
        Memos.insert(make_pair(KeyForAmount, numPossibilities));//We have found a new Memoized value
        return numPossibilities;//Return it after storing it
    }
};
int main()
{
    Change * temp = new Change();
    vector<int> TestCase = {1,2,3};
    cout << temp->ChangePossibilities(4, TestCase);
    delete temp;
    return 0;
}
