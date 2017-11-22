#include <iostream>
#include <vector>
using namespace std;
vector<int> mergeVectors(const vector<int>& v1, const vector<int>& v2){
    vector<int>MergedVector(v1.size()+v2.size());
    int v1Iter = 0;
    int v2Iter = 0;
    int currentIndexMerged = 0;
    while(currentIndexMerged < MergedVector.size()){
        //Check to see if either vector is empty
        bool isv1empty = v1.size()<=v1Iter;
        bool isv2empty = v2.size()<=v2Iter;

        if(!isv1empty && (isv2empty || v1[v1Iter] < v2[v2Iter])){
            MergedVector[currentIndexMerged] = v1[v1Iter];
            cout<<"Adding from v1: " << v1[v1Iter] <<" at " << v1Iter << endl;
            v1Iter++;
        }
        else{
            MergedVector[currentIndexMerged] = v2[v2Iter];
            cout<<"Adding from v2: " <<" at " << v2Iter << endl;
            v2Iter++;
        }
        currentIndexMerged++;
    }
    return MergedVector;
}

int main()
{
const vector<int> myVector     {3};
const vector<int> alicesVector {1, 5, 8, 12, 14, 19};
vector<int> mergedVector = mergeVectors(myVector, alicesVector);

cout << "[";
for (size_t i = 0; i < mergedVector.size(); ++i) {
    if (i > 0) {
        cout << ", ";
    }
    cout << mergedVector[i];
}
cout << "]" << endl;
// prints [1, 3, 4, 5, 6, 8, 10, 11, 12, 14, 15, 19]
    cout << "Hello world!" << endl;
    return 0;
}
