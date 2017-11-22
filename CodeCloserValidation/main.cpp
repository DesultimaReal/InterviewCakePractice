#include <iostream>
#include <stack>
using namespace std;
bool Validate(string CodeString){
    int isClosed = 0;
    for(char i: CodeString){
        if (i == '{' || i == '(' || i == '[') {
            isClosed ++;
        }
        else if(i == '}' || i == ')' || i == ']'){
            isClosed --;
        }
    }
    if(isClosed == 0)
        return true;
    return false;
}
bool ValidateR(string CodeString){
    /*
    push() : adds an item
    pop() : removes and returns the top item
    They can also include some utility methods:
    top() : returns the item on the top of the stack, without removing it.
    empty() : returns true if the stack is empty, false otherwise
    */
    int isClosed = 0;
    stack<char> Code;
    for(char i: CodeString){
        if (i == '{' || i == '(' || i == '[') {
            cout<< i <<" Pushing\n";
            Code.push(i);

        }
        else if(i == '}'){
            cout<< i <<" Popping\n";
            if(Code.top()=='{'){
                Code.pop();
            }
            else{
                return false;
            }

        }
        else if(i == ')'){
            cout<< i <<" Popping\n";
            if(Code.top()=='('){
                Code.pop();
            }
            else{
                return false;
            }

        }
        else if(i == ']'){
            cout<< i <<" Popping\n";
            if(Code.top()=='['){
                Code.pop();
            }
            else{
                return false;
            }

        }

    }
    if(Code.empty()){
        return true;
    }
    return false;
}
int main()
{
    string Code = "{[]}";
    ValidateR(Code) ? cout << "Yes" : cout << "No";
    return 0;
}
