#include<iostream>

using namespace std;

class Node{                                 //creation of doubly linked list using class
    public:
    int data;
    Node* next;
    Node* prev;
    // constructor of the doubly linked list
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
    // destructor of the doubly linked list
    ~Node(){
        int val = this->data;
        if (next != NULL){
            delete next;  // to deallocate the created heap we use "delete" function
            next = NULL;
        }
        cout<<"The memory free for node with data "<<val<<endl;
    }
};

void print_list(Node* &head){               //trsversing throught doubly linked list
    Node* pointer = head;
    while(pointer != NULL){
        cout<<pointer->data<<" -> ";
        pointer = pointer->next;
    }
    cout<<" NULL"<<endl;
}

void insertAThead(Node* &head , int data){    // inserting at head position in a linked list 
    Node* element = new Node(data);
    element->next = head;
    head->prev = element;
    head = element;
}

void insertAttail(Node* &tail, int data){
    Node* element = new Node(data);
    tail->next = element;
    element->prev = tail;
    tail = element;
}

void insertAtpositon(Node*&head  ,Node*&tail , int data , int position){
    if (position == 1){
        insertAThead(head , data);                      //function to insert at random position in the doubly linked list
        return;
    }
    else{
        Node* element = new Node(data);
        Node* temp = head;
        int curr = 1;
        while (curr < position-1){
            temp = temp->next;
            curr++;
        }
        if (temp->next == NULL){
            insertAttail(tail,data);
            return;
        }
        element->next = temp->next;
        temp->next = element;
        element->prev = temp;
    }
}

int get_length(Node* &head){               // finding the lenght of the doubly linked list
    int len = 0;
    Node* temp = head;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    return len;
}

void delete_element(Node*&head , Node *& tail, int position){
    if (position == 1){
        Node* temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
    else{
        Node* temp = head;
        int cnt = 1;
        while(cnt < position){
            prev = NULL;
            curr = curr->next
        }
           
    }
}


int main(){
    Node* node1 = new Node(100);
    Node* node2 = new Node(23);
    node1->prev = NULL;
    node1->next = node2;
    node2->next = NULL;
    node2->prev = node1;
    Node* head = node1;
    Node* tail = node2;
    print_list(head);
    cout<<"The length of the doubly linked list is "<<get_length(head)<<endl;
    insertAThead(head, 45);
    print_list(head);
    cout<<head->data<<" "<<head->next<<" "<<head->prev<<endl;
    insertAttail(tail,78);
    insertAttail(tail,91);
    print_list(head);
    cout<<tail->data<<" "<<tail->next<<" "<<tail->prev<<endl;
    cout<<get_length(head)<<endl;
    insertAtpositon(head,tail,67,4);
    insertAtpositon(head,tail,51,6);
    print_list(head);
    delete_element(head,tail,4);
    print_list(head);
    return 0;
}