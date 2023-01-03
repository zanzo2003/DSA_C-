#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* next;
    //constructor
    Node(int d){
        this->data = d;
        this->next = NULL;
    }
    //destructor
    ~Node(){
        int value = this->data;
        if (this->next != NULL){
            delete next;
            next = NULL;
        }
        cout<<"The value which is deleted is "<<value<<endl;
    }
};

void insertNode(int dat, int d, Node*&tail){
    Node* temp = tail;
    Node* element = new Node(dat);
    while (temp->data != d){
        temp = temp->next;
    }
    element->next = temp->next;
    temp->next = element;
}

void traverse(Node* &tail){
    Node*&temp = tail;
    while(tail->next != temp){
        cout<<tail->data<<" -> ";
        tail = tail->next;
    }
    cout<<endl;
}


int main(){
    Node* tail = NULL;
    insertNode(12,10,tail);
    traverse(tail);
    return 0;
}