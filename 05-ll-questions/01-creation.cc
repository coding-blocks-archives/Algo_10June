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

Node* deleteNode(Node* head, int dataToDelete){
    Node* cur = head;
    Node* previous = NULL;
    while(cur){
        if (cur->data == dataToDelete){
            // I have found a node to be deleted
            if (previous == NULL){
                // head is to be deleted
                head = cur->next;
                delete cur;
            }
            else {
                previous->next = cur->next; 
                delete cur;
            }
            break;
        }
        else {
            previous = cur;
            cur = cur->next;
        }
    }
    return head;
}

Node* midPt(Node* head){    // Get
    Node* slow = head;
    Node* fast = head;  // Set
    // GO
    while(slow && fast && fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* mergeSortedLists(Node* a, Node* b){
    if (a == NULL) return b;
    if (b == NULL) return a;

    if (a->data < b->data){
        a->next = mergeSortedLists(a->next, b);
        return a;
    }
    else {
        b->next = mergeSortedLists(a, b->next);
        return b;
    }
}

Node* mergeSort(Node* head){
    if (head == NULL || head->next == NULL){
        return head;
    }
    Node* middle = midPt(head);
    Node* l1 = head;
    Node* l2 = middle->next;
    middle->next = NULL;
    l1 = mergeSort(l1);
    l2 = mergeSort(l2);
    Node* ans = mergeSortedLists(l1, l2);
    return ans;
}
// ??? quickSort(Node* head){
// }

int lenLL(Node* head){
    Node* cur = head; 
    int cnt = 0;
    while(cur){ ++cnt; cur = cur->next;}
    return cnt;
}

Node* bubbleSort(Node* head){
    int len = lenLL(head);
    int cnt = len;
    for(int i = 0; i < len; ++i){
        Node* cur = head;
        Node* previous = NULL;
        while(cnt && cur && cur->next){
            Node* ahead = cur->next;
            if (cur->data > ahead->data){
                // swapping needs to be done
                if (previous == NULL){
                    cur->next = ahead->next;
                    ahead->next = cur;
                    head = ahead;
                    previous = ahead;
                }
                else{
                    cur->next = ahead->next; 
                    previous->next = ahead;
                    ahead->next = cur;
                    previous = ahead;
                }
            }
            else {
                previous = cur;
                cur = cur->next;
            }
        }
        --cnt;
    }
    return head;
}

Node* reverseList(Node* head){
    if (head == NULL) return;
    Node* remListHead = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return remListHead;
}

Node* addOne(Node* head){

// }
// ??? deleteDuplicates(Node* head){

// }
// ??? findLoop(Node* head){

// }
// ??? removeLoop(Node* head){

// }


int main(){
    // Node* head = createLL();
    // printLL(head);
    // int x; cin >> x;
    // head = deleteNode(head, x);
    // printLL(head);

    // Node* head = createLL();
    // printLL(head);
    // head = mergeSort(head);
    // printLL(head);

    Node* head = createLL();
    printLL(head);
    head = bubbleSort(head);
    printLL(head);
       
}