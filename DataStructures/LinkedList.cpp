#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node() {
        data = 0;
        next = NULL;
    }
    Node(int d) {
        this->data = d;
        this->next = NULL;
    }
    Node(int d, Node* next) {
        this->data = d;
        this->next = next;
    }
};

class LinkedList {
    Node* headNode;
    public:
    LinkedList() {
        this->headNode = NULL;
    }

    /*
    * Insert a new NODE at the end of the Linked List
    * @param data to be inserted in LinkedList
    */
    void insertNode(int data);

    /*
    * Insert a new  NODE at given index
    * @param data to be inserted in LinkedList
    * @param index where data will be inserted
    */
    void insertNodeAt(int data, int index);

    /*
    * Delete the last NODE of Linked List
    */
    void deleteNode();

    /*
    * Delete NODE at given index 
    * @param index where data will be deleted
    */
    void deleteNodeAt(int index);

    /*
    * Traverse and Prints the Linked List
    */
    void printList();
};

void LinkedList::insertNode(int data) {
    if(headNode == NULL) {
        Node* node = new Node(data);
        headNode = node;
        return;
    }
    Node* ptr = headNode;
    while(ptr->next != NULL) ptr = ptr->next;
    Node* node = new Node(data);
    ptr->next = node;
}

void LinkedList::insertNodeAt(int data, int index) {
    if(headNode == NULL) {
        cout<<"List is Empty Inserted at 0th Index"<<endl;
        insertNode(data);
        return;
    } 
    if(index == 0) {
        Node* node = new Node(data);
        node->next = headNode;
        cout<<"Inserted at : "<<index<<endl;
        headNode = node;
        return;
    }
    int count = 1;
    Node* slow = headNode;
    Node* fast = headNode->next;
    while(count != index && slow != NULL && fast != NULL) {
        slow = slow->next;
        fast = fast->next;
        count++;
    }
    if(count != index) {
        cout<<"Index out of Bounds."<<endl;
        return;
    }
    Node* node = new Node(data);
    slow->next = node;
    node->next = fast;
    cout<<"Inserted at : "<<index<<endl;
}

void LinkedList::deleteNode() {
    if(headNode == NULL) {
        cout<<"List is Empty."<<endl;
        return;
    }
    if(headNode->next == NULL) {
        cout<<"Deleted the last Node"<<endl;
        headNode = NULL;
        return;
    }
    Node* head = headNode;
    while(head->next->next != NULL) head = head->next;
    delete head->next;
    head->next = NULL;
    cout<<"Deleted the last Node"<<endl;
}
 
void LinkedList::deleteNodeAt(int index) {
    if(headNode == NULL) {
        cout<<"List is Empty."<<endl;
        return;
    }
    if(index == 0) {
        Node* head = headNode;
        headNode = headNode->next;
        delete head;
        cout<<"Deleted Node at index : 0"<<endl;
        return;
    }
    int count = 1;
    Node* slow = headNode;
    Node* fast = headNode->next;
    while(count != index && slow != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next;
        count++;
    }
    if(count != index) {
        cout<<"Index out of Bounds."<<endl;
        return;
    }
    Node* n = fast;
    fast = fast->next;
    slow->next = fast;
    delete n;
    cout<<"Deleted Node at index : "<<index<<endl;
}

void LinkedList::printList(){
    if(headNode == NULL){
        cout<<"List : Empty."<<endl;
        return;
    }
    Node* head = headNode;
    cout<<"List : ";
    while(head->next != NULL) {
        cout<<head->data<<" --> ";
        head = head->next;
    }
    cout<<head->data<<endl;
}


int main() {
    bool exit = false;
    int choice,data,index;
    LinkedList List;

    while(!exit) {
        cout<<"\n\nLinked List Operations Menu \n"; 
        cout<<"Press 1 to Insert at End \n";
        cout<<"Press 2 to Insert at Index \n";
        cout<<"Press 3 to Delete from End \n"; 
        cout<<"Press 4 to Delete at Index \n";
        cout<<"Press 5 to Print LinkedList \n";
        cout<<"Press 6 to Exit \n\n";
        cin>>choice;
        switch (choice)
        {
        case 1:
            cout<<"\nEnter Data to insert : ";
            cin>>data;
            List.insertNode(data);
            List.printList();
            break;
        case 2:
            cout<<"\nEnter Data to insert : ";
            cin>>data;
            cout<<"\nEnter Index : ";
            cin>>index;
            List.insertNodeAt(data,index);
            List.printList();
            break;
        case 3:
            List.deleteNode();
            List.printList();
            break;
        case 4:
            cout<<"\nEnter Index : ";
            cin>>index;
            List.deleteNodeAt(index);
            List.printList();
            break;
        case 5:
            List.printList();
            break;
        case 6:
            exit = true;
            break;
        default:
            cout<<"\nInvalid Choice.";
            break;
        }
    }
    return 0;
}
