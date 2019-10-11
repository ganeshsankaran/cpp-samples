#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct LinkedList {
    Node* head;
    Node* tail;
};

LinkedList* array2List(int* arr, int len) {
    LinkedList* list = new LinkedList;
    Node* head = new Node;
    list->head = head;

    Node* p = head;
    for(int i = 0; i < len; i++) {
        p->data = arr[i];
        Node* next = new Node;
        if(i == len - 1) {
            list->tail = p;
            p->next = NULL;
        }
        else {
            p->next = next;
            p = p->next;
        }
    }

    return list;
}

void insertNode(LinkedList* list, int data, int index) {
    Node* p = list->head;
    if(index == 0) { // add a note to head of list
        Node* tmp = new Node;
        tmp->data = data;
        tmp->next = p;
        list->head = tmp; // update list's head if node is added at beginning
    }
    else {
        for(int i = 0; i < index; i++) { 
            if(i == index - 1) { // go until the node before the index of insertion
                Node* tmp = new Node;
                tmp->data = data;
                tmp->next = p->next; // make new node point to node after current node
                p->next = tmp; // make current node point to new node
            }
            if(p->next) {
                p = p->next;
            }
        }
        if(!p->next) { // update list's tail if node is added at end
            list->tail = p;   
        }
    }
}

void deleteNode(LinkedList* list, int index) {
    Node* p = list->head;
    if(index == 0) { // delete node at beginning
        list->head = p->next; // update list's head if node is deleted at beginning
        delete p;
    }
    else {
        for(int i = 0; i < index; i++) { 
            if(i == index - 1) { // go until node at index of deletion
                Node* tmp = p->next->next;
                delete p->next; // delete node after current node
                p->next = tmp; // make current node point to node after deleted node
            }
            if(p->next) {
                p = p->next;
            }
        }
        if(!p->next) {
            list->tail = p; // update list's tail if node is deleted at end
        }
    }
}

void freeLinkedList(LinkedList* list) {
    Node* h = list->head;
    while(h) {
        Node* tmp = h;
        h = h->nextNode;
        delete tmp;
    }

    // do this only if you are clearing the list
    // list->head = NULL;
    // list->tail = NULL;

    //otherwise
    delete list;
}

void printList(LinkedList* list) {
    Node* p = list->head;
    while(p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    int arr1[] = {1,2,3,4,5,4,4,4,4,4};
    LinkedList* l1 = array2List(arr1, 10);
    printList(l1);
    insertNode(l1, 6, 3);
    insertNode(l1, 7, 6);
    printList(l1);
    deleteNode(l1, 3);
    printList(l1);
    deleteNode(l1, 5);
    insertNode(l1, 4, 0);
    printList(l1);

}