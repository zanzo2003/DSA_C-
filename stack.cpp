//Program for stack and its operations
#include<iostream>

using namespace std;

class Stack{
    public:
    int *arr;
    int size;
    int top;
    // constructor behaviour
    Stack(int size){
        this->size = size;
        arr = new int[size];
        top = -1;
    }
    void push(int element){
        if (size - top > 1 ){
            top++;
            arr[top] = element ;
        }
        else{
            cout<<"Stack overflow, no space available"<<endl;
        }
    }
    void pop(){
        if (top>=0){
            top--;
        }
        else{
            cout<<"Stack underflow, no element available"<<endl;
        }
    }
    void peek(){
        if (top>=0 && top<size){
            cout<<"The top element is "<<arr[top]<<endl;
        }
        else{
            cout<<"Stack is empty"<<endl;
        }
    }
    bool isEmpty(){
        if (top == -1){
            return true;
        }
        else{
            return false;
        }
    }

};

int main(){
    Stack s(5);
    s.push(14);
    s.push(34);
    s.push(56);
    s.peek();
    s.pop();
    s.pop();
    s.push(45);
    if (s.isEmpty()){
        cout<<"The stack is empty "<<endl;
    }
    else{
        cout<<"The Stack is not empty"<<endl;
    }
    return 0;
}