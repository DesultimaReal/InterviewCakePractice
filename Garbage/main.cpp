#include <iostream>

using namespace std;
void change(int i[]){
    i[0] = 5;
    i[1] = 6;
    i[2] = 7;
}

int main()
{
    int waysmap[3] = {1,2,3};
    change(waysmap);
    for(int i = 0; i < 3; i++){
        cout << waysmap[i];
    }
    return 0;
}
