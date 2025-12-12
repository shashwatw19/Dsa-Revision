#include<iostream>
using namespace std;
class Queue{
    private :
    int front ;
    int rear ;
    int *arr;
    int size;

    public : 
    Queue(int s){
        front = -1;
        rear = -1;
        arr = new int[size];
    }
    void enqueue(int element){
        if(isFull()){
            cout<<"queue is full";
        }
        if(front == -1)
            front = 0;
        arr[++rear] = element;
    }
    int dequeue(){
        if(isEmpty()){
            cout<<"queue is empty";
        }
        if(front == rear)
            front = rear = -1;

        return arr[front++];
    }
    int peek(){
        if(isEmpty()){
            cout<<"queue is empty";
        }
        return arr[front];
    }
    bool isEmpty(){
        return front == -1 && rear == -1;
    }
    bool isFull(){
        return rear == size - 1;
    }
    void display(){
        if(isEmpty()){
            cout<<"queue is empty"<<endl;
        }
        for(int i = front ; i <=rear ; i++){
            cout<<arr[i]<<endl;
        }
    }
};

int main(){
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Front element: " << q.peek() << endl;

    q.display();
}