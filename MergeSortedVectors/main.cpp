#include <iostream>
#include <vector>

using namespace std;
//This program Merges two sorted vectors.
vector<int> mergeVectors(vector<int> v1, vector<int> v2){
    vector<int> Merged;
    Merged;

    int iter1=0;
    int iter2=0;
    int v1size=v1.size();//6
    int v2size=v2.size();//6

    while(iter1<v1size || iter2<v2size){

        if(v1[iter1] < v2[iter2] || iter2 >= v2size){//If the current v1 is less
            cout<<"a";
            Merged.push_back(v1[iter1]);
            iter1++;
        }
        else if(v1[iter1] >= v2[iter2] || iter1 >= v1size){
            cout<<"b";
            Merged.push_back(v2[iter2]);
            iter2++;
        }
    }
    return Merged;
}

int main()
{
    const vector<int> myVector {3, 4, 6, 10, 11, 15};
    const vector<int> alicesVector {1, 5, 8, 12, 14, 15, 19};

    vector<int> mergedVector = mergeVectors(myVector, alicesVector);

    cout << "[";
    for (size_t i = 0; i < mergedVector.size(); ++i) {
        if (i > 0) {
            cout << ", ";
        }
        cout << mergedVector[i];
    }
    cout << "]" << endl;
    return 0;
}
