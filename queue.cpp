#include<iostream>

using namespace std;

class Queue{
    int* arr;
    int size;
    int qfront;
    int rear;
    //constructor of queue
    public:
    Queue(int size){
        this->size = size;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }
    void enqueue(int data){          // to insert an element in a queue
        if (rear == (size)){
            cout<<"The queue is full"<<endl;
            return;
        }
        else{
            arr[rear] = data;
            rear++;
            return;
        }
    }

    int dequeue(){                   // to delete an element from a queue
        if (qfront == rear){
            cout<<"The queue is empty ."<<endl;
            return -1;
        }
        else{
            int val = arr[qfront];
            qfront = qfront + 1;
            if (qfront == rear){
                qfront = 0;
                rear = 0;
            }
            return val;
        }
    }

    bool empty(){                 //To check if queue is empty or not empty
        if (qfront == rear){
            return true;
        }
        else{
            return false;
        }
    }

    int front_element(){           // to check the front of a queue
        if (qfront == rear){
            return -1;
        }
        else{
            return arr[qfront];
        }
    }

    int no_of_elements(){   // function for no of elements.
        return (rear - qfront);
    }
};


int main(){
    Queue q(5);
    q.enqueue(1);
    q.enqueue(3);
    q.enqueue(243);
    q.dequeue();

    cout<<"the fisrt element is : "<<q.front_element()<<endl;
    cout<<"the fisrt element is : "<<q.front_element()<<endl;
    if (q.empty()){
        cout<<"The queue is empty"<<endl;
    }
    else{
        cout<<"The queue is not empty"<<endl;
    }
    cout<<"THe number of elements are : "<<q.no_of_elements()<<endl;


    return 0;
}
