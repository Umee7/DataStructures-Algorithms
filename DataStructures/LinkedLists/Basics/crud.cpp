#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int val){
        data = val;
        next = nullptr;
    }
};

void printLL(Node *head) {
    while(head!=nullptr){
        cout<<head->data<<" -> ";
        head = head->next;
    }
    cout<<"NULL"<<"\n";
}

void insertAtEnd(Node *&head, int value) {
    Node *newNode = new Node(value);
    if(head==nullptr) {
        head = newNode;
        return;
    }
    
    Node *temp = head;
    while(temp->next!=nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAtFront(Node *&head, int value) {
    Node *newNode = new Node(value);
    
    newNode->next = head;
    head = newNode;
}

void deleteNode(Node *&head, int value) {
    if(head == nullptr) return;
    Node *temp = head;
    if(head->data == value) {
        head = head->next;
        delete temp;
        return;
    }
    while(temp->next != NULL) {
        if(temp->next->data == value) {
            Node *nodeToDelete = temp->next;
            temp->next = temp->next->next;
            delete nodeToDelete;
            return;
        }
        temp = temp->next;
    }
}

int findLength(Node *head) {
    int length = 0;
    if(head == nullptr) return length;
    while(head != nullptr) {
        length++;
        head = head->next;
    }
    return length;
}

int findMiddleLL(Node *head) {
    Node *slow = head;
    Node *fast = head;
    while(fast!= nullptr && fast->next!=nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}
int main() {
    Node *head = nullptr;
    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);
    insertAtEnd(head, 50);
    insertAtEnd(head, 60);
    insertAtEnd(head, 70);
    printLL(head);
    int length = findLength(head);
    cout<<"length: "<<length<<"\n";
    int middle = findMiddleLL(head);
    cout<<middle<<"\n";
}
