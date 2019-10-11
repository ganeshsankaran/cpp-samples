#include <iostream>
using namespace std;

class LinkedList {
public:
    LinkedList();
    ~LinkedList();
    LinkedList(const LinkedList& source);
    LinkedList& operator =(const LinkedList& source);
    void insert(int value);
    void clear();
    void print() const;
    bool search(int value);
private:
    struct Node {
        int data;
        Node* next;
    };
    Node* head;
    Node* tail;

    bool searchHelper(Node* head, int value);
};

LinkedList::LinkedList() {
    head = NULL;
    tail = NULL;
}

LinkedList::~LinkedList() {
    clear();
}

LinkedList::LinkedList(const LinkedList& source) {
    head = NULL;
    tail = NULL;
    
    Node *p = source.head;
    while(p) {
        insert(p->data);
        p = p->next;
    }
}

LinkedList& LinkedList::operator=(const LinkedList& source) {
    clear();
    
    Node *p = source.head;
    while(p) {
        insert(p->data);
        p = p->next;
    }

    return *this; // return entirety of object, not just the pointer
}

void LinkedList::insert(int value) {
    //Node* p = new Node{value, NULL}; causes compilation error
    Node* p = new Node; // don't delete after function returns
    p->data = value;
    p->next = NULL;

    if(!head) {
        head = p;
    }
    else {
        tail->next = p;
    }
    tail = p;
}

void LinkedList::clear() {
    Node* p = head;
    while(p) {
        Node* tmp = p->next;
        delete p;
        p = tmp;
    }
    head = NULL;
    tail = NULL;
}
void LinkedList::print() const {
    Node* p = head;
    while(p) {
        cout << p-> data << " ";
        p = p->next;
    }
    cout << endl;
}

bool LinkedList::search(int value) {
    return searchHelper(head, value);
}

bool LinkedList::searchHelper(Node* head, int value) {
    if(!head) {
        return false;
    }

    if(head->data == value) {
        return true;
    }

    return searchHelper(head->next, value);
}

int main() {
    LinkedList* l1 = new LinkedList;
    for(int i = 0; i < 3; i++) {
        l1->insert(i * 2 + 1);
    }
    l1->print();
    LinkedList l2(*l1);
    l2.print();

    LinkedList l3 = l2;
    l3.print();
    delete l1;
    cout << l2.search(2) << endl;
    cout << l3.search(3) << endl;
    return 0;
}