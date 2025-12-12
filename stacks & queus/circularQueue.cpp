#include<iostream>
using namespace std;
class queue{
    private :
    int size , 
    int arr;
    int currsize;
    int front , rear;

    public :
    queue(int capacity){
        size = capacity;
        front = -1;
        rear = -1;
        arr = new int[capacity];
    }

    void push(int data){
        if(currsize == size){
            cout<<"queue is full.."
            return;
        }
        if(currsize == 0){
            front = 0; rear = 0;
        }
        rear = (rear + 1) % size
        arr[rear] = data;
        currsize++;

    }

    int pop(){
        if(currsize == 0){
            cout<<"queue is empty"<<endl;
            return -1;
        }
        int element = arr[front];
        if(currsize == 1){
            front = rear = -1;
        }
        else{
            front = (front + 1)% size;
        }
        currsize--;
        return element;
            
    }
    int top(){
        if(currsize == 0){
            return -1;
        }
        return arr[front];
    }
    
}
int main(){

}