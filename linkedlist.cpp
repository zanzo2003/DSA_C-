#include<iostream>

using namespace std;

class Node{                                          //class for creating a linked list also known as constructor of the
    public:                                          // linked list
    int data;
    Node *next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
    ~Node(){                     
        int value = this->data;                       //This is the destructor of the linked list and removes or deletes the 
        if (this->next != NULL){                      // element from the linked list .
            delete next;  // to deallocate the created heap we use "delete" function
            this->next = NULL;
        }
        cout<<"The value which is being removed is "<<value<<endl;
    }

};

void insertAthead(Node* &head , int data){          // function for inserting at the head of the node
    Node * temp = new Node(data);
    temp->next = head;
    head = temp;
}

void printList(Node* &head){                         // function for traversing through the linked list
    Node *temp = head;
    while(temp != NULL){
        cout<<temp->data<<" -> ";
        temp = temp -> next;
    } 
    cout<<"Null"<<endl;
}
void insertAtend(Node *& tail , int data){             // function for inserting at the end or at tail 
    Node *temp = new Node(data);
    tail->next = temp;
    tail = tail->next;
}
void insertAtposition(Node* &tail ,Node* &head , int data , int position,int cur = 1 ){    // function to insert at any position of the linked list
    if (position == 1 ){
        insertAthead(head,data);
        return;
    }
    Node* element = new Node(data);
    Node* temp = head;
    while (cur < position - 1){
        temp = temp->next;
        cur = cur + 1;
    }
    if (temp->next == NULL){
        insertAtend(tail,data);
        return;
    }
    element->next = temp->next;
    temp->next = element;
}

void deleteElement(Node * &tail,Node* &head, int position){
    if (position == 1 ){
        Node * temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else{
        Node * curr = head;
        Node * temp = NULL;
        int cnt = 1 ;
        while (cnt < position){
            temp = curr;
            curr = curr->next;
            cnt++;
        }
        temp->next = curr->next;
        curr->next = NULL;
        if (temp->next == NULL){
            tail = temp;
        }
        delete curr;
    }
}
void reverseNode(Node*&head, int k)
{
	if (!head)
		return;
	Node* current = head;
	Node* next = NULL;
	Node* prev = NULL;
	int count = 0;
	while (current != NULL && count < k) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
		count++;
	}
	if (next != NULL)
		head->next = current;
	head = prev;
}

int main(){
    Node *node1 = new Node(1);
    Node *head = node1;
    Node *tail = node1;
    insertAtend(tail,2);
    insertAtend(tail,3);
    insertAtend(tail,4);
    insertAtposition(tail,head,5,5);
    insertAtposition(tail,head,6,6);
    printList(head);
    cout<<"This is the tail " << tail->data<<endl;
    cout<<"This is the head "<<head->data<<endl;
    reverseNode(head,3);
    printList(head);
    cout<<"This is the tail " << tail->data<<endl;
    cout<<"This is the head "<<head->data<<endl;

    return 0;
}