#include<iostream>
#include<bits/stdc++.h>
using namespace std;
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

    bool empty() const {
        return currSize == 0;
    }

    bool full() const {
        return currSize == capacity;
    }

    void push(int data){
        if(full()){
            cerr << "Queue is full\n";
            return;
        }
        s1.push(data);
        ++currSize;
    }

    int pop(){
        if(empty()){
            cerr << "Queue is empty\n";
            return -1;
        }
        if(!s2.empty()){
            int data = s2.top();
            s2.pop();
            --currSize;
            return data;
        } else {
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            int data = s2.top();
            s2.pop();
            --currSize;
            return data;
        }
    }

    int top(){
        if(empty()){
            cerr << "Queue is empty\n";
            return -1;
        }
        if(!s2.empty()){
            return s2.top();
        } else {
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            return s2.top();
        }
    }
};
