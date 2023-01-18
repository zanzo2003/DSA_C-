#include<iostream>
#include<bits/stdc++.h>
#include<cmath>
using namespace std;

struct node{
    int data;
    struct node* next;
}*head=NULL,*last = NULL;

void addlast(int d){
    struct node* temp = (struct node* )malloc(sizeof(struct node));
    temp->data = d;
    if(head == NULL){
        temp->next = temp;
        head = temp;
        last = head;
    }
    else{
        temp->next = head;
        last->next = temp;
        last = temp;
    }
}

void viewList(){
    struct node* temp;
    temp = head;
    do{
        cout<<temp->data<<endl;
        temp = temp->next;
    }while (temp != head);  
}

void splitList(int n){
    struct node* temp;
    temp = head;
    while(n--){
        temp = temp->next;
    }  
    struct node* temp2 = temp;
    int even = 0;
    while(temp != head){
        if (even){
            cout<<temp->data<<endl;
        }
        temp = temp->next;
        even = (even+1)%2;
    }
    int odd = 1;
    while(temp2 != head){
        if(odd){
            cout<<temp2->data<<endl;
        }
        temp2 = temp2->next;
        odd = (odd + 1)%2;
    }
}

int main(){
    int n;
    cin>>n;
    int a;
    for(int i = 0; i < n; i++){
        cin>>a;
        addlast(a);
    }
    splitList(n/2);
    viewList();
    return 0;
}