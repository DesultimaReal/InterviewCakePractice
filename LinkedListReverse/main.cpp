#include <iostream>
using namespace std;

class LinkedListNode{
public:
int Value;
LinkedListNode * Next;

    LinkedListNode(int intValue):
        Value(intValue),
        Next(NULL)
       {
       }
    int ReturnValue(){
        return Value;
    }
};
class LinkedList{
public:
    LinkedListNode * head, *tail;
    LinkedList(){
        head = NULL;
        tail = NULL;
    }
    void createNode(int intValue){
        LinkedListNode * temp = new LinkedListNode(intValue);
        if(head == NULL){
            head = temp;
            tail = temp;
            temp = NULL;
        }
        else{
            tail->Next = temp;
            tail = temp;
        }
    }
    void PrintList(LinkedListNode * CurrentNode){
        cout<< CurrentNode->ReturnValue();
        while(CurrentNode->Next != NULL){
            CurrentNode=CurrentNode->Next;
            cout << "-> " << CurrentNode->ReturnValue();
        }cout<<endl;
    }
    void SwapHeads(){

    }
LinkedListNode * ReverseInPlace(LinkedListNode * headNode){
        LinkedListNode * Current = headNode;
        LinkedListNode * NextNode = NULL;
        LinkedListNode * PreviousNode = NULL;
        while(Current){
            NextNode = Current->Next;//Save the next node
            Current->Next = PreviousNode;//Reverse the current->next pointer
            PreviousNode = Current;
            Current = NextNode;
        }
        //Swap our heads and tails
        LinkedListNode * temp = head;
        head = tail;
        tail = head;

        return PreviousNode;
}
};



int main()
{
    LinkedList * OurList = new LinkedList();
    OurList->createNode(5);
    OurList->createNode(4);
    OurList->createNode(3);

    OurList->PrintList(OurList->head);
    OurList->ReverseInPlace(OurList->head);
    OurList->PrintList(OurList->head);

    delete OurList;
    return 0;
}
