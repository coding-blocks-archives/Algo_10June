// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;     // self referential classes
    Node(int d){
        data = d;
        next = NULL;
    }
};

Node* createLL(){
    int x;
    Node* head = NULL;
    Node* tail = NULL;

    while(x){
        cin >> x;
        if (x == -1) break;
        Node* newNode = new Node(x);
        if (head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            // tail->next = newNode;
            (*tail).next = newNode;
            tail = tail->next;
        }
    }
    return head;
}

void printLL(const Node* head){
    const Node* cur = head;
    while(cur){
        cout << cur->data << "-->";
        // cur->data = 2;
        cur = cur->next;    // ++cur
    }
    cout << endl;
}

??? deleteNode(Node* head, int dataToDelete){
}
??? mergeSort(Node* head){
}
??? quickSort(Node* head){
}
??? bubbleSort(Node* head){

}
??? addOne(Node* head){

}
??? deleteDuplicates(Node* head){

}
??? findLoop(Node* head){

}
??? removeLoop(Node* head){

}


int main(){
    Node* head = createLL();
    printLL(head);
       
}