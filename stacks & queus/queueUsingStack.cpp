#include <iostream>
#include <stack>
class Queue{
    private :
    stack<int> s1;
    stack<int> s2;
    int capacity ;
    int currSize;
    public:
    
    Queue(int size){
        capacity = size;
        currSize = 0;
    }

    void push(int data){
        if (currSize == capacity) {
            cout << "Queue is full\n";
            return;
        }

        // Move all elements from s1 to s2
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        
        // Push new element
        s1.push(data);
        currSize++;

        // Move everything back to s1
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop(){
        if (s1.empty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        int data = s1.top();
        s1.pop();
        currSize--;
        return data;
    }

    int top(){
        if (s1.empty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return s1.top();
    }

};

int main(){

}