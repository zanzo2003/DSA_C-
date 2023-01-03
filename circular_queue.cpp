#include<iostream>

using namespace std;

class Queue{
    int *arr;
    int size;
    int front;
    int rear;
    public:
    Queue(int size){
        this->size = size;
        arr = new int[size];
        front = rear = -1;
    }
    bool enqueue(int data){      // to add element in a circular queue
        if ((front == 0 && rear == size-1) || (rear == (front - 1)%(size - 1))){  // if the queue is full
            return false;
        }
        else if (front == -1){  // if the element to be inserted is the 1st element
            front = rear = 0;
        }
        else if ((rear == size - 1)&&(front != 0)){  // to maintain cylic structure of a circular queue
            rear = 0;
        }
        else{              // to maintain normal condition of the queue
            rear ++;
        }
        arr[rear] = data;
        return true;
    }

    int dequeue(void){
        if (front == -1){   // if queue is empty
            return -1;
        }
        int ans = arr[front];      // to store dequeued element
        arr[front] = -1;
        if (front == size - 1){     // if the dequeueing element is the last element
            front = 0;
        }
        else if(front == rear){    // if there is only one element
            front = rear = -1;
        }
        else{        // normal condition
            front++;
        }
        return ans;
    }

    void printAtFront(){
        cout<<"The element at the front of the queue is "<<arr[front]<<endl;
    }
};

int main(){
    Queue q (10);
    q.enqueue(3);
    q.enqueue(2);
    q.enqueue(12);
    q.printAtFront();
    q.dequeue();
    q.printAtFront();
    return 0;
}