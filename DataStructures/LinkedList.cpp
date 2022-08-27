#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) {
        data = d;
        next = NULL;
    }
};


Node* insertNode(int data, Node* hnode) {
    if(hnode == NULL) {
        Node* node = new Node(data);
        return node;
    }
    Node* head = hnode;
    while(head->next != NULL) head = head->next;
    Node* node = new Node(data);
    head->next = node;
    return hnode;
}


Node* insertNodeAt(int data, int index, Node* hnode) {
    if(hnode == NULL) {
        cout<<"List is Empty inserted at : 0"<<endl;
        return insertNode(data,hnode);
    } 
    if(index == 0) {
        Node* node = new Node(data);
        node->next = hnode;
        cout<<"inserted at : "<<index<<endl;
        return node;
    }
    int count = 1;
    Node* slow = hnode;
    Node* fast = hnode->next;
    while(count != index && slow != NULL && fast != NULL) {
        slow = slow->next;
        fast = fast->next;
        count++;
    }
    if(count != index) {
        cout<<"index out of Bounds."<<endl;
        return hnode;
    }
    Node* node = new Node(data);
    slow->next = node;
    node->next = fast;
    cout<<"inserted at : "<<index<<endl;
    return hnode;
}

Node* deleteNode(Node* hnode) {
    if(hnode == NULL) {
        cout<<"List is Empty."<<endl;
        return hnode;
    }
    if(hnode->next == NULL) {
        cout<<"deleted the last Node"<<endl;
        return NULL;
    }
    Node* head = hnode;
    while(head->next->next != NULL) head = head->next;
    delete head->next;
    head->next = NULL;
    cout<<"deleted the last Node"<<endl;
    return hnode;
}


Node* deleteNodeAt(int index,Node* hnode) {
    if(hnode == NULL) {
        cout<<"List is Empty."<<endl;
        return hnode;
    }
    if(index == 0) {
        Node* head = hnode;
        hnode = hnode->next;
        delete head;
        cout<<"deleted Node at index : 0"<<endl;
        return hnode;
    }
    int count = 1;
    Node* slow = hnode;
    Node* fast = hnode->next;
    while(count != index && slow != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next;
        count++;
    }
    if(count != index) {
        cout<<"index out of Bounds."<<endl;
        return hnode;
    }
    Node* n = fast;
    fast = fast->next;
    slow->next = fast;
    delete n;
    cout<<"deleted Node at index : "<<index<<endl;
    return hnode;
}


void printList(Node* hnode){
    if(hnode == NULL){
        cout<<"List : Empty."<<endl;
        return;
    }
    Node* head = hnode;
    cout<<"List : ";
    while(head->next != NULL) {
        cout<<head->data<<" --> ";
        head = head->next;
    }
    cout<<head->data<<endl;
}


int main() {
    int arr[] = {42,5,31,-31,78,0,1,33};
    Node* hnode = NULL;
    for(int num : arr) {
        hnode = insertNode(num,hnode);
    }
    // hnode = insert(31,hnode);
    // printList(hnode);
    // hnode = insertNodeAt(22,8,hnode);
    // hnode = deleteNode(hnode);
    printList(hnode);
    hnode = deleteNodeAt(7,hnode);
    printList(hnode);
    return 0;
}