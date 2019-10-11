//not complete

#include <iostream>
using namespace std;

struct Node { 
    Node* prevNode;
    int data;
    Node* nextNode;
};

struct DLinkedList { 
    Node* head;
    Node* tail;
};

DLinkedList* createSmallLinkedList(int x, int y) {
    DLinkedList* newList = new DLinkedList;
    newList->head = NULL;
    newList->tail = NULL;
    Node* head = new Node;
    head->data = x;
    head->nextNode = new Node;
    head->nextNode->data = y;
    head->nextNode->nextNode = NULL;
    head->nextNode->prevNode = head;
    newList->head = head;
    newList->tail = head->nextNode;
    return newList;
}

void insertAtHead(DLinkedList* list, int x) {
    Node* newHead = new Node;
    newHead->nextNode = list->head;
    newHead->data = x;
    newHead->prevNode = NULL;
    if(!list->head) {
        list->tail = newHead;
    }
    else {
        list->head->prevNode = newHead;
    }
    list->head = newHead;
}
/* 
void insertAtTail(DLinkedList* list, int x) {
    Node* newHead = new Node;
    newHead->nextNode = NULL;
    newHead->data = x;
    if(!list->head) {
        list->head = newHead;
    }
    else {
        list->tail->nextNode = newHead;
    }
    list->tail = newHead;
}
*/

void deleteNode(DLinkedList* list, int value) { 
    if(!list || list->head == NULL) {
        return;
    }
    Node* h = list->head;
    while(h && h->data != value) {
        h = h->nextNode;
    }
    if(!h) {
        return;
    }
    if(h->prevNode) {
        h->prevNode->nextNode = h->nextNode;
    }
    if(h->nextNode) {
        h->nextNode->prevNode = h->prevNode;
    }

    if(h == list->head) {
        list->head = h->nextNode;
    }
    if(h == list->tail) {
        list->tail = h->prevNode;
    }
    delete h;

}
void printLinkedList(DLinkedList* list) {
    Node* h = list->head; //h is a traversal pointer
    while(h) { //h is not null
        cout << h->data << " ";
        h = h->nextNode;
    }
    cout << endl;
}

void freeLinkedList(DLinkedList* list) {
    Node* h = list->head;
    while(h) {
        Node* tmp = h;
        h = h->nextNode;
        delete tmp;
    }

    //do this only if you are clearing the list
    list->head = NULL;
    list->tail = NULL;

    //otherwise
    delete list;
}

int main() {
    DLinkedList* l1 = createSmallLinkedList(10, 20);
    printLinkedList(l1);
    insertAtHead(l1, 30); 
    //insertAtTail(l1, -10);
    printLinkedList(l1);
    deleteNode(l1, 30);
    printLinkedList(l1);
    freeLinkedList(l1);

    return 0;
}

