#include <iostream>
#include <vector>
using namespace std;
//This code makes a vector of products that include all numbers except the current position.
//Example: 1,2,3 becomes 6(3x2),3(3x1),2(2x1)
template <class myType>
void printVector (vector<myType> v){
    cout << v[0];
    for(int i = 1; i < v.size(); i++){
        cout << ", " << v[i];
    }cout << endl;
}
vector<int> prodsRightOf(vector<int>v){
    vector<int> RightOf(v.size());
    int prod = 1;
    RightOf[v.size()-1] = prod;
    int a = 1;
    for(int i = v.size()-1; i > 0; i--){
        int b = a+1;
        prod*=v[v.size()-a];
        RightOf[v.size()-b] = prod;
        a++;
    }
    return RightOf;
}
vector<int> prodsLeftOf(vector<int>v){
    vector<int> leftOf(v.size());
    int prod = 1;
    for(int i = 0; i < v.size(); i++){
        leftOf[i] = prod;
        //cout <<"x: " <<prod << endl;
        prod *= v[i];
    }
    return leftOf;
}
vector<int> productExceptAt(vector<int> v){
    vector<int> RightOf = prodsRightOf(v);
    vector<int> LeftOf = prodsLeftOf(v);
    for(int i = 0; i < LeftOf.size(); i++){
        LeftOf[i] *= RightOf[i];
    }
    return LeftOf;
}
int main()
{
    vector<int> v = {1,7,3,4};
    printVector(productExceptAt(v));

    return 0;
}
